#![no_main]
#[macro_use] extern crate libfuzzer_sys;
extern crate sane;

fuzz_target!(|data: &[u8]| {
    if let Ok(s) = std::str::from_utf8(data) {
        let _: std::result::Result<sane::Value, sane::de::Error> = sane::from_str(s);
    }
});
