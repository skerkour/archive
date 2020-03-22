//! A [SANE]-parsing library
//!
//! This library implements a [SANE] v1.0.0 compatible parser,
//! primarily supporting the [`serde`] library for encoding/decoding
//! various types in Rust.
//!
//! SANE itself is a simple, ergonomic, and readable configuration format:
//!
//! ## SANE values
//!
//! A value in SANE is represented with the `Value` enum in this crate:
//!
//! ```rust,ignore
//! pub enum Value {
//!     String(String),
//!     Integer(i64),
//!     Float(f64),
//!     Boolean(bool),
//!     List(List),
//!     Map(Map),
//! }
//! ```
//!
//! SANE is similar to JSON but design to be *human to machine* instead of *machine to machine*.
//!
//! ## Parsing SANE
//!
//! The easiest way to parse a SANE document is via the `Value` type:
//!
//! ```rust
//! use sane::Value;
//!
//! let value = "foo = 'bar'".parse::<Value>().unwrap();
//!
//! assert_eq!(value["foo"].as_str(), Some("bar"));
//! ```
//!
//! The `Value` type implements a number of convenience methods and
//! traits; the example above uses `FromStr` to parse a `str` into a
//! `Value`.
//!
//! ## Deserialization and Serialization
//!
//! This crate supports [`serde`] 1.0 with a number of
//! implementations of the `Deserialize`, `Serialize`, `Deserializer`, and
//! `Serializer` traits. Namely, you'll find:
//!
//! * `Deserialize for Value`
//! * `Serialize for Value`
//! * `Deserializer for de::Deserializer`
//! * `Serializer for ser::Serializer`
//! * `Deserializer for Value`
//!
//! This means that you can use Serde to deserialize/serialize the
//! `Value` type. You can also
//! use the `Deserializer`, `Serializer`, or `Value` type itself to act as
//! a deserializer/serializer for arbitrary types.
//!
//! An example of deserializing with SANE is:
//!
//! ```rust
//! use serde::{Deserialize} ;
//! use sane;
//!
//! #[derive(Deserialize)]
//! struct Config {
//!     ip: String,
//!     port: Option<u16>,
//!     keys: Keys,
//! }
//!
//! #[derive(Deserialize)]
//! struct Keys {
//!     github: String,
//!     travis: Option<String>,
//! }
//!
//! fn main() {
//!     let config: Config = sane::from_str(r#"
//!         ip = '127.0.0.1'
//!
//!         keys = {
//!             github = 'xxxxxxxxxxxxxxxxx',
//!             travis = 'yyyyyyyyyyyyyyyyy',
//!         }
//!     "#).unwrap();
//!
//!     assert_eq!(config.ip, "127.0.0.1");
//!     assert_eq!(config.port, None);
//!     assert_eq!(config.keys.github, "xxxxxxxxxxxxxxxxx");
//!     assert_eq!(config.keys.travis.as_ref().unwrap(), "yyyyyyyyyyyyyyyyy");
//! }
//! ```
//!
//! You can serialize types in a similar fashion:
//!
//! ```rust
//! use serde::{Serialize};
//! use sane;
//!
//! #[derive(Serialize)]
//! struct Config {
//!     ip: String,
//!     port: Option<u16>,
//!     keys: Keys,
//! }
//!
//! #[derive(Serialize)]
//! struct Keys {
//!     github: String,
//!     travis: Option<String>,
//! }
//!
//! fn main() {
//!     let config = Config {
//!         ip: "127.0.0.1".to_string(),
//!         port: None,
//!         keys: Keys {
//!             github: "xxxxxxxxxxxxxxxxx".to_string(),
//!             travis: Some("yyyyyyyyyyyyyyyyy".to_string()),
//!         },
//!     };
//!
//!     let sane_str = sane::to_string(&config).unwrap();
//! }
//! ```
//!
//! [SANE]: https://gitlab.com/bloom42/sane
//! [Cargo]: https://crates.io/
//! [`serde`]: https://serde.rs/

#![doc(html_root_url = "https://docs.rs/sane/0.2.1")]
#![deny(missing_docs)]

#[macro_use]
extern crate serde;

pub mod value;
#[doc(no_inline)]
pub use value::Value;
mod datetime;

pub mod ser;
#[doc(no_inline)]
pub use ser::{to_string, to_string_pretty, to_vec, Serializer};
pub mod de;
#[doc(no_inline)]
pub use de::{from_slice, from_str, Deserializer};
mod tokens;

#[doc(hidden)]
mod macros;

mod spanned;
#[doc(no_inline)]
pub use spanned::Spanned;
