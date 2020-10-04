const Level = require('./level');
const clone = require('./clone');
const { stdout, console } = require('./writers');
const { isBrowser } = require('./exec_env');

/**
 * @typedef {Object} LoggerOptions
 * @property {number} level - The minimum logging level
 */


/** Logger class */
class Logger {
  constructor(options) {
    this._level = Level.DEBUG;
    this._fields = {};
    this._writer = isBrowser ? console : stdout;
    this._insert_timestamp = true;
    this._timestamp_field_name = 'timestamp';
    this._message_field_name = 'message';
    this._level_field_name = 'level';
    this._hooks = [];

    // config after initialisation
    this.config(options);
  }

  _log(level, message) {
    if (level < this._level) {
      return;
    }

    const event = clone(this._fields);

    // handle message
    if (message === undefined || message === null) {
      // do nothing
    } else if (typeof message === 'string' && message.length > 0) {
      event[this._message_field_name] = message;
    } else if (message instanceof Error) {
      event.error_name = message.name;
      event[this._message_field_name] = message.message;
    } else {
      event[this._message_field_name] = JSON.stringify(message);
    }

    // handle timestamp
    if (this._insert_timestamp === true) {
      event[this._timestamp_field_name] = new Date().toISOString();
    }

    // default case: do not insert level field
    switch (level) {
      case Level.DEBUG:
        event[this._level_field_name] = 'debug';
        break;
      case Level.INFO:
        event[this._level_field_name] = 'info';
        break;
      case Level.WARN:
        event[this._level_field_name] = 'warning';
        break;
      case Level.ERROR:
        event[this._level_field_name] = 'error';
        break;
      case Level.FATAL:
        event[this._level_field_name] = 'fatal';
        break;
      default:
        break;
    }

    this._hooks.forEach(hook => hook(event));

    this._writer.write(event);
  }

  /**
   * configure the logger with the given options
   * @param {LoggerOptions} options - the options to configure the logger
   */
  config(options) {
    if (!options) {
      return;
    }
    if (options.level !== undefined) {
      this._level = options.level;
    }
    if (options.fields !== undefined) {
      this._fields = options.fields;
    }
    if (options.writer !== undefined) {
      this._writer = options.writer;
    }
    if (options.insert_timestamp !== undefined) {
      this._insert_timestamp = options.insert_timestamp;
    }
    if (options.timestamp_field_name !== undefined) {
      this._timestamp_field_name = options.timestamp_field_name;
    }
    if (options.message_field_name !== undefined) {
      this._message_field_name = options.message_field_name;
    }
    if (options.level_field_name !== undefined) {
      this._level_field_name = options.level_field_name;
    }
    if (options.hooks !== undefined) {
      this._hooks = options.hooks;
    }
  }


  /**
   * create a copy of the logger, add the given fields to it and return it
   * @param {Object} fields - fields to add to the logger instance
   * @return {Logger} a new Logger which embed the given fields
   */
  with(fields) {
    const newFields = fields || {};
    // clone the logger instance
    const newLogger = Object.assign(
      Object.create(Object.getPrototypeOf(this)),
      this,
    );
    newLogger._fields = { ...this._fields, ...newFields };
    return newLogger;
  }

  /**
   * log an event with the DEBUG level
   * @param {string} message - the message to log
   */
  debug(message) {
    this._log(Level.DEBUG, message);
  }

  /**
   * log an event with the INFO level
   * @param {string} message - the message to log
   */
  info(message) {
    this._log(Level.INFO, message);
  }

  /**
   * log an event with the WARN level
   * @param {string} message - the message to log
   */
  warn(message) {
    this._log(Level.WARN, message);
  }

  /**
   * log an event with the ERROR level
   * @param {string} message - the message to log
   */
  error(message) {
    this._log(Level.ERROR, message);
  }

  /**
   * log an event with the FATAL level then exit(1)
   * @param {string} message - the message to log
   */
  fatal(message) {
    this._log(Level.FATAL, message);
    process.exit(1);
  }

  /**
   * log an event without level nor message
   * @param {Object} [fields] - additional fields to add to the event (optional)
   */
  track(fields) {
    const newLogger = this.with(fields);
    newLogger._log(Level.NONE);
  }
}


module.exports = Logger;
