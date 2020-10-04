# Bloom legacy export

**On [February 29, 2020](https://fatalentropy.com/2019-december-update/) All the data on https://legacy.bloom.sh will be deleted.**

I sincerly apologize for the inconvenience, but it is currently costing too much (1k$ / mo) and I can't afford that while nobody is
paying to access Bloom in beta.

To remediate that, the new version (coming soon) will have paying plans to create a sustainable project.

We provide the following program to automatically backup data from https://legacy.bloom.sh.

The legacy code will remains available: https://gitlab.com/bloom42/bloom/tree/legacy but I will no
longer maintain it.

Contact: https://bloom.sh/contact

1. [Installation](#installation)
2. [Usage](#usage)

---------

For Windows you can find the detailed instructions here: https://help.bloom.sh/en/article/how-to-export-legacy-data-on-windows-10-uwautd/

## Installation

### Using Go

Install go: https://golang.org/


Then
```sh
$ go get -u gitlab.com/bloom42/bloom_legacy_export
```

### Using prebuilt binaries

Download the binary for your platform on the release page: https://gitlab.com/bloom42/bloom_legacy_export/-/releases

## Usage

In a shell, go to an empty folder, then run
```sh
$ bloom_legacy_export
```
and follow the instructions
