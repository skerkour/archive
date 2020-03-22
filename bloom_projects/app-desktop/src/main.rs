#![windows_subsystem = "windows"]

use web_view::*;

fn main() {
    web_view::builder()
        .title("Bloom - Open internet services")
        .content(Content::Url("https://bloom.sh"))
        .size(2500, 1500)
        .resizable(true)
        .debug(true)
        .user_data(())
        .invoke_handler(|_webview, _arg| Ok(()))
        .run()
        .unwrap();
}
