<p align="center">
  <h3 align="center">astro.js</h3>
  <p align="center">Fast, elegant, structured, pluggable and isomorphic logging for Javascript ⚡</p>
</p>

--------

[Make logging great again](https://kerkour.com/blog/logging)


<!-- [![NPM Package](https://img.shields.io/badge/npm-@bloom42/astro-blue.svg)](https://www.npmjs.com/package/@bloom42/astro)
[![NPM Release](https://img.shields.io/npm/v/@bloom42/astro.svg?colorB=blue)](https://www.npmjs.com/package/@bloom42/astro)
[![Known Vulnerabilities](https://snyk.io/test/github/bloom42/astro-js/badge.svg?targetFile=package.json)](https://snyk.io/test/github/bloom42/astro-js?targetFile=package.json)

[![NPM](https://nodei.co/npm/@bloom42/astro.png?stars=true)](https://www.npmjs.com/package/@bloom42/astro)
 -->

1. [Quickstart](#quickstart)
2. [Configuraiton](#configuraiton)
3. [Examples](#examples)
4. [Contributing](#contributing)
5. [Licensing](#licensing)
6. [Sponsoring](#sponsoring)
7. [Security](#security)

--------


## Quickstart

```bash
$ npm i @bloom42/astro
```

```javascript
const { log } = require('@bloom42/astro');

const log2 = log.with({ num: 2 });

log.info('hello world');
log2.info('hello world');
log.with({ lol: 42 }).error('fatal knock out');
log2.with({ num: 3, pi: 3.14 }).info('hello world');
log2.info('hello world');
log2.track({ description: 'event without message nor level' });
```


## Configuration
```javascript
// default configuration
const options = {
  level: Level.DEBUG,
  fields: {},
  writer: isBrowser ? console : stdout,
  insert_timestamp: true,
  timestamp_field_name: 'timestamp',
  message_field_name: 'message',
  level_field_name: 'level',
  hooks: [],
};

log.config(options);
```


```typescript
log.config(options: any)
log.with(fields: any): Logger
log.debug(message: string)
log.info(message: string)
log.warn(message: string)
log.error(message: string)
log.fatal(message: string) // log with the "fatal" level then exit(1)
log.track(fields: any) // log an event without level nor message
```


## Examples

[See the examples folder](https://github.com/bloom42/astro-js/tree/master/examples)


## Contributing

Thank you for your interest in contributing! Please refer to
[https://bloom.sh/contribute](https://bloom.sh/contribute) for guidance.



## Licensing

See `LICENSE.txt` and [https://bloom.sh/licensing](https://bloom.sh/licensing)


## Sponsoring

Bloom is a free and open source project. If you are interested in supporting this project, the core team
and the contributors please visit our
[sponsoring page](https://bloom.sh/become-a-sponsor) ✌️


## Security

If you found a security issue affecting this project, please do not open a public issue and refer to our
[dedicated security page](https://bloom.sh/security) instead. Tahnk you.
