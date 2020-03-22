const { log } = require('../lib');

const log2 = log.with({ num: 2 });

log.info('hello world');
log2.info('hello world');
log.with({ lol: 42 }).error('fatal knock out');
log2.with({ num: 3, pi: 3.14 }).info('hello world');
log2.info('hello world');
log2.track({ description: 'event without message nor level' });
log2.error(new Error('my error'));
