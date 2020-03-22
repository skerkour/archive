use regex::Regex;
use serde::{Deserialize, Serialize};
use std::{env, fs};

#[derive(Clone, Debug, Default, Serialize, Deserialize)]
pub struct Config {
    pub rust_env: String,
    pub assets_folder: String,
    pub sentry_url: String,
    pub api_url: String,
    pub api_secret: String,
    pub data_folder: String,
    pub concurrency: u32,
}

fn get_env(var: &str) -> String {
    match env::var(var) {
        Ok(v) => v,
        Err(_err) => panic!("missing ENV var: {}", var),
    }
}

impl Config {
    pub fn new() -> Config {
        let config_file_contents =
            fs::read_to_string("phaser.sane").expect("Error reading phaser.sane");

        let decoded: Config =
            sane::from_str(&config_file_contents).expect("Error parsing config file");

        return replace_env(decoded);
    }
}

fn replace_env(mut config: Config) -> Config {
    let re = Regex::new(r"\$\{[A-Z_0-9]*\}").expect("error compiling env regex");
    let patterns: &[_] = &['$', '{', '}'];

    // rust_env
    for match_ in re.find_iter(&config.rust_env.clone()) {
        let match_str = match_.as_str();
        config.rust_env = config
            .rust_env
            .replace(match_str, &get_env(match_str.trim_matches(patterns)));
    }

    // assets_folder
    for match_ in re.find_iter(&config.assets_folder.clone()) {
        let match_str = match_.as_str();
        config.assets_folder = config
            .assets_folder
            .replace(match_str, &get_env(match_str.trim_matches(patterns)));
    }

    // sentry_url
    for match_ in re.find_iter(&config.sentry_url.clone()) {
        let match_str = match_.as_str();
        config.sentry_url = config
            .sentry_url
            .replace(match_str, &get_env(match_str.trim_matches(patterns)));
    }

    // api_url
    for match_ in re.find_iter(&config.api_url.clone()) {
        let match_str = match_.as_str();
        config.api_url = config
            .api_url
            .replace(match_str, &get_env(match_str.trim_matches(patterns)));
    }

    // api_secret
    for match_ in re.find_iter(&config.api_secret.clone()) {
        let match_str = match_.as_str();
        config.api_secret = config
            .api_secret
            .replace(match_str, &get_env(match_str.trim_matches(patterns)));
    }

    // data_folder
    for match_ in re.find_iter(&config.data_folder.clone()) {
        let match_str = match_.as_str();
        config.data_folder = config
            .data_folder
            .replace(match_str, &get_env(match_str.trim_matches(patterns)));
    }

    return config;
}
