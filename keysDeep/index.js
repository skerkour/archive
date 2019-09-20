var _ = require('lodash');

module.exports = function(obj) {
  return _.reduce(obj, function(acc, value, key) {
    if (typeof value === "object" && value != null) {
      return _.concat(acc, _.map(keysDeep(value), function(vv, i) {
        return key + '.'+vv;
      }));
    } else {
      return _.concat(acc, [key]);
    }
  }, []);
}
