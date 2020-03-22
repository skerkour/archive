const isBrowser = typeof window !== 'undefined';
const isNode = typeof window === 'undefined' && typeof process !== 'undefined';
const isWebWorker = typeof self !== 'undefined' && typeof postMessage === 'function'; // eslint-disable-line no-restricted-globals

module.exports = {
  isBrowser,
  isNode,
  isWebWorker,
};
