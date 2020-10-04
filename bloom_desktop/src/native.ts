import { Subject } from 'rxjs';

// const { EventEmitter } = require('events');
const { promisify } = require('util');
const { NativeAdaptater: Native } = require('bloom_native');


// The `NativeAdaptater` class provides glue code to abstract the `poll`
// interface provided by the Neon class. It may be constructed and used
// as a normal `EventEmitter`, including use by multiple subscribers.
class NativeAdaptater { // extends EventEmitter {
  // This map contains all our { resolve, reject } promises object for our in flight calls from the
  // call method.
  private inflightCalls = new Map<string, any>();

  // native is our Native class instancied once
  private native: any = null;

  notification: Subject<any> = new Subject<any>();

  constructor() {
    // super();

    // Create an instance of the Neon class
    this.native = new Native();

    // Neon does not provide `Promise` return values from asynchronous
    // tasks, but it does use node style callbacks that may be trivially
    // promisified.
    // Neon uses a reference to `this` to unwrap the Rust struct. The `poll`
    // method is bound to `native` to ensure access.
    const poll = promisify(this.native.poll.bind(this.native));

    // Marks the emitter as shutdown to stop iteration of the `poll` loop
    // this.isShutdown = false;

    // The `loop` method is called continuously to receive data from the Rust
    // work thread.
    const loop = async () => { // eslint-disable-line arrow-body-style
      // for (;;) {
      //   try {
      //     const event = await poll(); // eslint-disable-line no-await-in-loop
      //     console.log(event);
      //     const { id, data, error } = event;
      //     if (event) {
      //       if (this.inflightCalls.has(id)) {
      //         const { resolve, reject } = this.inflightCalls.get(id)!;
      //         this.inflightCalls.delete(id);
      //         // check if the event returns data or error
      //         if (error) {
      //           reject(error);
      //         } else {
      //           resolve(data);
      //         }
      //       } else {
      //         // Emit the event
      //         this.emit('event', data);
      //       }
      //     }
      //   } catch (err) {
      //     this.emit('error', err);
      //   }
      // }
      return (
        poll()
          .then((message: any) => {
            // Timeout on poll, no data to emit
            if (!message) {
              return;
            }

            const { id, data, error } = message;

            if (id !== undefined && this.inflightCalls.has(id)) {
              const { resolve, reject } = this.inflightCalls.get(id)!;
              this.inflightCalls.delete(id);

              // check if the message holds data or error
              if (error) {
                reject(error);
              } else {
                // here, data.type does not interest us
                resolve(data.data);
              }
              return;
            }

            // Emit the notification
            this.notify(data);
          })
          // Emit errors
          // .catch((err: any) => this.emit('error', err))
          .catch((err: any) => this.notification.error(err))
          // Schedule the next iteration of the loop. This is performed with
          // a `setImmediate` to extending the promise chain indefinitely
          // and causing a memory leak.
          .then(() => (window as any).setImmediate(loop, 10))
      );
    };

    // Start the polling loop
    loop();
  }

  call(data: any = {}): Promise<any> {
    return new Promise((resolve, reject) => {
      const callUuid: string = '1';
      this.inflightCalls.set(callUuid, { resolve, reject });
      this.native.call({ id: callUuid, data });
    });
  }

  // this method is called when received messages does not contains an 'id' field and thus are not
  // responses to async calls
  private notify(message: any) {
    // this.emit('notification', data);
    this.notification.next(message);
  }
}

export default new NativeAdaptater();
