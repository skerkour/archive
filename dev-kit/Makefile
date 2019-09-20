.PHONY: docker docker_release release docker_push

NAME = dev-kit
DIST_DIR = target
VERSION := $(shell cat VERSION.txt | tr -d '[:space:]')
DOCKER_IMAGE = registry.gitlab.com/bloom42/$(NAME)
COMMIT = $(shell git rev-parse HEAD)

all: docker

docker:
	docker build -t $(DOCKER_IMAGE) .

release:
	git tag v$(VERSION)
	git push origin v$(VERSION)

docker_release: docker
	docker tag $(DOCKER_IMAGE):latest $(DOCKER_IMAGE):$(VERSION)
	docker push $(DOCKER_IMAGE):$(VERSION)

docker_push:
	docker push $(DOCKER_IMAGE):latest
