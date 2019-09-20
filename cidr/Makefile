.PHONY: all test release build

VERSION := $(shell cat version.go| grep "\sVersion =" | cut -d '"' -f2)
NAME := cidr

all: build

test:
	go tool vet -all -shadowstrict .
	go test -race -covermode=atomic .

build:
	go build -o $(NAME) .

release:
	git tag v$(VERSION)
	git push origin v$(VERSION)

clean:
	rm -rf $(NAME)
