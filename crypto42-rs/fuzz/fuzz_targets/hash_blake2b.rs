#![no_main]

use libfuzzer_sys::fuzz_target;
use crypto42;

fuzz_target!(|data: &[u8]| {
    let _ = crypto42::hash::blake2b::hash(data, None).expect("error hashing data");
});
