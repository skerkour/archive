# NewsBot

[![GoDoc](https://godoc.org/github.com/bloom42/newsbot?status.svg)](https://godoc.org/github.com/bloom42/newsbot)
[![GitHub release](https://img.shields.io/github/release/bloom42/newsbot.svg)](https://github.com/bloom42/newsbot/releases/latest)
[![Build Status](https://travis-ci.org/bloom42/newsbot.svg?branch=master)](https://travis-ci.org/bloom42/newsbot)
[![Docker image](https://img.shields.io/badge/docker-bloom42/newsbot-blue.svg)](https://hub.docker.com/r/bloom42/newsbot)

newsbot helps you to manage the information overflow and addiction problem: automated [Hacker News](https://news.ycombinator.com) curation every 12 hours.

1. [Live version](#live-version)
2. [Available commands](#available-commands")
3. [Configuration example](#configuration-example)
4. [Usage](#usage)
5. [License](#license)

-------------------

## Live Version

[https://t.me/DailyHNBot](https://t.me/DailyHNBot)




## Available comands

See [https://github.com/bloom42/newsbot/blob/master/commands.txt](https://github.com/bloom42/newsbot/blob/master/commands.txt)



## Configuration example

```bash
$ cat .env
DATABASE_URL="postgres://user:pass@host..."
TELEGRAM_ADMIN="123456780" # The admin s chat ID
TELEGRAM_BOT_TOKEN="xxxxx:xxxxx" # required
GO_ENV="production" # or debug
ALGOLIA_APP_ID="" # default to UJ5WYC0L7X
ALGOLIA_API_KEY="" # default to 8ece23f8eb07cd25d40262a1764599b1
ALGOLIA_INDEX="" # default to Item_production_ordered
```



## Usage

```bash
$ newsbot
```


## License

See `LICENSE.txt` and [https://opensource.bloom.sh/licensing](https://opensource.bloom.sh/licensing)
