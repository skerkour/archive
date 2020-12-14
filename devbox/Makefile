NAME = $(shell cat version/version.go| grep "\sName" | cut -d '"' -f2)
VERSION := $(shell cat version/version.go| grep "\sVersion\s=" | cut -d '"' -f2)
COMMIT = $(shell git rev-parse HEAD)
DATE := $(shell date +"%Y-%m-%d")
GO_PKG = $(shell cat go.mod | grep module | cut -d' ' -f2)
DOCKER_IMAGE = registry.gitlab.com/bloom42/devbox
DIST_DIR = dist


.PHONY: all
all: build

.PHONY: fmt
fmt:
	go fmt ./...

.PHONY: test
test:
	go test ./...

.PHONY: clean
clean:
	rm -rf $(DIST_DIR)

.PHONY: tidy
tidy:
	go mod tidy


.PHONY: build
build:
	go build -o $(DIST_DIR)/$(NAME) -ldflags "-X $(GO_PKG)/version.GitCommit=$(COMMIT) \
		-X $(GO_PKG)/version.UTCBuildTime=`TZ=UTC date -u '+%Y-%m-%dT%H:%M:%SZ'` \
		-X $(GO_PKG)/version.GoVersion=`go version | cut -d' ' -f 3 | cut -c3-`"


.PHONY: build_static
build_static:
	CGO_ENABLED=0 go build -o $(DIST_DIR)/$(NAME) -a -ldflags "-extldflags "-static" -w -s \
		-X $(GO_PKG)/version.GitCommit=$(COMMIT) \
		-X $(GO_PKG)/version.UTCBuildTime=`TZ=UTC date -u '+%Y-%m-%dT%H:%M:%SZ'` \
		-X $(GO_PKG)/version.GoVersion=`go version | cut -d' ' -f 3 | cut -c3-`"


.PHONY: install
install:
	go install -a -ldflags "-extldflags "-static" -w -s \
		-X $(GO_PKG)/version.GitCommit=$(COMMIT) \
		-X $(GO_PKG)/version.UTCBuildTime=`TZ=UTC date -u '+%Y-%m-%dT%H:%M:%SZ'` \
		-X $(GO_PKG)/version.GoVersion=`go version | cut -d' ' -f 3 | cut -c3-`"
	devbox install
