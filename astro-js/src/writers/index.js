const StdoutWriter = require('./stdout');
const ConsoleWriter = require('./console');

module.exports = {
  stdout: new StdoutWriter(),
  console: new ConsoleWriter(),
};
