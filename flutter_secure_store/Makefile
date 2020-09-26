.PHONY: lint fmt fmt_check test release

lint:
	flutter analyze

fmt:
	flutter format lib/** test/**

fmt_check:
	flutter format -n lib/** test/**

test:
	- flutter test

release:
	- git checkout master
	- git merge dev
	- git push
	- git checkout dev
