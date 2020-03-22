.PHONY: all clean re dev build

all: build

build:
	mkdocs build
	mv dist public

re: clean all

clean:
	rm -rf public


dev:
	mkdocs serve -a localhost:8081
