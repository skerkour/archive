"use strict";

var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

var StdoutWriter = function () {
  function StdoutWriter() {
    _classCallCheck(this, StdoutWriter);
  }

  _createClass(StdoutWriter, [{
    key: "write",
    value: function write(event) {
      // eslint-disable-line class-methods-use-this
      process.stdout.write(JSON.stringify(event) + "\n");
    }
  }]);

  return StdoutWriter;
}();

module.exports = StdoutWriter;