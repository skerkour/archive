DIST_DIR = dist
NAME = bloom_legacy_export
VERSION := $(shell cat version.go| grep "\sVersion =" | cut -d '"' -f2)


.PHONY: all
all: linux macos windows

.PHONY: clean
clean:
	rm -rf $(DIST_DIR)

.PHONY: re
re: clean all

.PHONY: release
release:
	git tag v$(VERSION)
	git push origin v$(VERSION)


.PHONY: linux
linux:
	CGO_ENABLED=0 GOOS=linux go build -a -ldflags '-extldflags "-static"' -o $(DIST_DIR)/linux/$(NAME) .

.PHONY: macos
macos:
	CGO_ENABLED=0 GOOS=darwin go build -a -ldflags '-extldflags "-static"' -o $(DIST_DIR)/macos/$(NAME) .

.PHONY: windows
windows:
	CGO_ENABLED=0 GOOS=windows go build -a -ldflags '-extldflags "-static"' -o $(DIST_DIR)/windows/$(NAME).exe .
