# Scann

[![GoDoc](https://godoc.org/github.com/z0mbie42/scann?status.svg)](https://godoc.org/github.com/z0mbie42/scann)
[![GitHub release](https://img.shields.io/github/release/z0mbie42/scann.svg)](https://github.com/z0mbie42/scann/releases/latest)
[![Build Status](https://travis-ci.org/z0mbie42/scann.svg?branch=master)](https://travis-ci.org/z0mbie42/scann)

Summarise Code ANNotations (NOTE, TODO, FIXME, BUG)

1. [Installation](#installation)
2. [Usage](#usage)
3. [Configuration](#configuration)


---------------------------------------

## Installation

### Using go (nightly)
```bash
$ go get -u github.com/z0mbie42/scann
```

### Binary releases
[https://github.com/z0mbie42/scann/releases/latest](https://github.com/z0mbie42/scann/releases/latest)



## Usage

```bash
$ scann # will recursively parse files for annotations
testdata/main.go:4: TODO: lorem ipsum
```



## Configuration

`scann` can be configured using a `.scann.san` file. It uses the [SAN](http://astrocorp.net/san) configuration file format.


By default `scann` will search in the current directory then  recursively updward to find a `.scann.san`
configuration file, however a file can be specified using the `-c` flag.

| Field | Type   | Default value | Description |
| ----- | ------ | ------- | -------- |
| format | `string` | `"console"` | Configure the ouput format, available formats are: [console] |
| ignore | `[string]` | `[".git/**"]` | Ignore files according to Glob patterns (`**` are supported) |

### Example
```bash
$ cat .scann.san
ignore = [ ".git/**" ]
