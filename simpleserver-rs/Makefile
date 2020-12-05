.PHONY: build_dev
build_dev:
	cargo build


.PHONY: build
build:
	cargo build --release

.PHONY: build_static
build_static:
	cargo build --target x86_64-unknown-linux-musl --release
	mv target/x86_64-unknown-linux-musl/release/simpleserver target/release/simpleserver


.PHONY: fmt
fmt:
	cargo fmt


.PHONY: run
run:
	cargo run


.PHONY: check
check:
	cargo check


.PHONY: docker
docker:
	docker build -t simpleserver:latest .


.PHONY: lint
lint:
	cargo fmt -- --check
	cargo clippy -- -D warnings


.PHONY: test
test:
	cargo test
