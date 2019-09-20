.PHONY: build test release

VERSION := $(shell cat version.go | grep "\sVersion\s=" | cut -d '"' -f2)
COMMIT = $(shell git rev-parse HEAD)

build:
	go build ./...

test:
	go vet ./...
	go test -v -race ./...

release:
	git tag v$(VERSION)
	git push origin v$(VERSION)
