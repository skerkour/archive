class StdoutWriter {
  write(event) { // eslint-disable-line class-methods-use-this
    process.stdout.write(`${JSON.stringify(event)}\n`);
  }
}

module.exports = StdoutWriter;
