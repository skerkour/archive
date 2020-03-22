.PHONY: build all publish clean re docs

build:
	./node_modules/.bin/babel src --out-dir lib

all: build

publish:
	npm publish

clean:
	rm -rf lib

re: clean all

docs:
	./node_modules/.bin/esdoc
