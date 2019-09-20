.PHONY: all clean re dev dist submodules build lint
.PHONY: rocket signal sane bitflow phaser

all: build rocket sane signal

build: dist
	npm run build

re: clean all

clean:
	rm -rf dist

deploy:
	firebase deploy

dev:
	npm run serve

lint:
	npm run lint

submodules:
	git submodule update --recursive --remote

dist:
	mkdir -p dist

public: dist
	cp -r src/public/* dist/

rocket: dist
	cd projects/rocket/docs && mkdocs build

signal: dist
	cd projects/signal/docs && mkdocs build

sane: dist
	cd projects/sane && mkdocs build

bitflow: dist
	cd projects/bitflow/docs && mkdocs build

phaser: dist
	cd projects/phaser/docs && mkdocs build
