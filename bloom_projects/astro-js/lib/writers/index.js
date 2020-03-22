'use strict';

var StdoutWriter = require('./stdout');
var ConsoleWriter = require('./console');

module.exports = {
  stdout: new StdoutWriter(),
  console: new ConsoleWriter()
};