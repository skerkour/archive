<p align="center">
  <h3 align="center">SANE-rs</h3>
  <p align="center">SANE Serialization and Deserialization for Rust</p>
</p>

--------

<!-- [![Build Status](https://travis-ci.org/bloom42/sane-rs.svg?branch=master)](https://travis-ci.org/bloom42/sane-rs) -->
[![sane-rs crate](https://img.shields.io/crates/v/sane.svg)](https://crates.io/crates/sane)
[![sane-rs documentation](https://docs.rs/sane/badge.svg)](https://docs.rs/sane)

Spec: [https://gitlab.com/bloom42/sane/sane](https://gitlab.com/bloom42/sane/sane)

Compatible with SANE version: [v1.0.0](https://gitlab.com/bloom42/sane/sane/blob/master/versions/v1.0.0-beta.md)

1. [Documentation](#documentation)
2. [Contributing](#contributing)
3. [Licensing](#licensing)
4. [Sponsoring](#sponsoring)
5. [Security](#security)

--------


## Documentation

See the [docs.rs/sane](https://docs.rs/sane)


## Contributing

Thank you for your interest in contributing! Please refer to
[https://bloom.sh/contribute](https://bloom.sh/contribute) for guidance.



## Licensing

See `LICENSE.txt` and [https://bloom.sh/licensing](https://bloom.sh/licensing)

From an original work by [alexcrichton](https://github.com/alexcrichton): [toml-rs](https://github.com/alexcrichton/toml-rs) -
commit [d729bf9c53fcfe8f1e5506a938b88d81526b55a4](https://github.com/alexcrichton/toml-rs/commit/d729bf9c53fcfe8f1e5506a938b88d81526b55a4)



## Sponsoring

Bloom is a free and open source project. If you are interested in supporting this project, the core team
and the contributors please visit our
[sponsoring page](https://bloom.sh/become-a-sponsor) ✌️


## Security

If you found a security issue affecting this project, please do not open a public issue and refer to our
[dedicated security page](https://bloom.sh/security) instead. Tahnk you.

<!-- <p align="center">
  <h3 align="center">SANE-rs</h3>
  <p align="center">SANE Serialization and Deserialization for Rust</p>
</p>

--------

[![Build Status](https://travis-ci.org/bloom42/sane-rs.svg?branch=master)](https://travis-ci.org/bloom42/sane-rs)
[![sane-rs crate](https://img.shields.io/crates/v/sane.svg)](https://crates.io/crates/sane)
[![sane-rs documentation](https://docs.rs/sane/badge.svg)](https://docs.rs/sane)

Spec: [https://opensource.bloom.sh/sane](https://opensource.bloom.sh/sane)

Compatible with SANE version: [v1.0.0](https://opensource.bloom.sh/sane/versions/v1.0.0)


1. [Usage](#usage)
1. [Contributing](#contributing)
2. [License](#license)

-------------------


## Usage

```rust
//! An example showing off the usage of `Deserialize` to automatically decode
//! SANE into a Rust `struct`

#![deny(warnings)]

use sane;
use serde::{Deserialize};

/// This is what we're going to decode into. Each field is optional, meaning
/// that it doesn't have to be present in SANE.
#[derive(Debug, Deserialize)]
struct Config {
    global_string: Option<String>,
    global_integer: Option<u64>,
    server: Option<ServerConfig>,
    peers: Option<Vec<PeerConfig>>,
}

/// Sub-structs are decoded from tables, so this will decode from the `[server]`
/// table.
///
/// Again, each field is optional, meaning they don't have to be present.
#[derive(Debug, Deserialize)]
struct ServerConfig {
    ip: Option<String>,
    port: Option<u64>,
}

#[derive(Debug, Deserialize)]
struct PeerConfig {
    ip: Option<String>,
    port: Option<u64>,
}

fn main() {
    let sane_str = r#"
        global_string = "test"
        global_integer = 5
        server = { ip = "127.0.0.1", port = 80 }
        peers = [
            {
                ip = "127.0.0.1",
                port = 8080,
            },
            { ip = "127.0.0.1" },
        ]
"#;

    let decoded: Config = sane::from_str(sane_str).unwrap();
    println!("{:#?}", decoded);
}
```


## Contributing

Thank you for your interest in contributing! Please refer to
[https://opensource.bloom.sh/contributing](https://opensource.bloom.sh/contributing) for guidance.

## License

See `LICENSE.txt` and [https://opensource.bloom.sh/licensing](https://opensource.bloom.sh/licensing)

From an original work by [alexcrichton](https://github.com/alexcrichton): [toml-rs](https://github.com/alexcrichton/toml-rs) -
commit [d729bf9c53fcfe8f1e5506a938b88d81526b55a4](https://github.com/alexcrichton/toml-rs/commit/d729bf9c53fcfe8f1e5506a938b88d81526b55a4) -->
