'use strict';

var isBrowser = typeof window !== 'undefined';
var isNode = typeof window === 'undefined' && typeof process !== 'undefined';
var isWebWorker = typeof self !== 'undefined' && typeof postMessage === 'function'; // eslint-disable-line no-restricted-globals

module.exports = {
  isBrowser: isBrowser,
  isNode: isNode,
  isWebWorker: isWebWorker
};