# rp

[![GitHub release](https://img.shields.io/github/release/z0mbie42/rp.svg)](https://github.com/z0mbie42/rp/releases/latest)
[![Build Status](https://travis-ci.org/z0mbie42/rp.svg?branch=master)](https://travis-ci.org/z0mbie42/rp)

The simplest recursive string replacer. Use it with caution

1. [Installation](#installation)
2. [Usage](#usage)

-------------------

## Installation

### Using go (nightly)

```bash
$ go get -u github.com/z0mbie42/rp
```

### Binary releases

[https://github.com/z0mbie42/rp/releases/latest](https://github.com/z0mbie42/rp/releases/latest)



## Usage

### rp
```bash
$ rp OLD NEW
```

### help
```bash
$ rp help
The simplest recursive string replacer. Use it with caution

Usage:
  rp <old> <new> [flags]
  rp [command]

Available Commands:
  help        Help about any command
  version     Display the version and build information

Flags:
  -h, --help                 help for rp
  -i, --ignore stringArray   Fiels to ignore (glob pattern) (default [.git/**])
  -m, --max-filesize int     Ignore files larger than the given size (in bytes) (default 500000000)
  -p, --plan                 Display modifications without actually doing it

Use "rp [command] --help" for more information about a command.
```
