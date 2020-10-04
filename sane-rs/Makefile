.PHONY: build clean re dev test build_static release fuzz
.PHONY: crates_login crates_publish

NAME := $(shell cat Cargo.toml | grep "^name\s=" | cut -d '"' -f2)
VERSION := $(shell cat Cargo.toml | grep "^version\s=" | cut -d '"' -f2)
COMMIT = $(shell git rev-parse HEAD)

all: build

build:
	cargo build

test:
	cargo test

lint:
	cargo +nightly fmt
	cargo clippy

audit:
	cargo audit

fuzz:
	cargo +nightly fuzz run from_str

release:
	git tag v$(VERSION)
	git push origin v$(VERSION)

crates_login:
	cargo login ${CRATES_TOKEN}

crates_publish:
	cargo publish
