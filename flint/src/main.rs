mod error;
mod rule;

use clap::{App, Arg};
use ignore::Walk;
use serde::{Serialize, Deserialize};
use std::fs;
use error::FlintError;
use rule::{Kind, Rule};
use globset::Glob;
use regex::Regex;


#[derive(Clone, Debug, Deserialize, Serialize)]
pub struct Config {
    pub rules: Vec<rule::ConfigRule>,
}


pub fn parse_config(config: Config) -> Result<Vec<rule::Rule>, FlintError> {
    let rules: Vec<_> = config.rules.into_iter().map(|rule_to_parse| {
        let convention = match rule_to_parse.convention.as_str() {
            "any" => rule::Convention{regex: Regex::new(r".*")?, name: Some("any".to_string())},
            "kebab_case" => rule::Convention{regex: Regex::new(r"^[a-z][a-z\-\d]*[a-z\d]$")?, name: Some("kebab_case".to_string())},
            "snake_case" => rule::Convention{regex: Regex::new(r"^[a-z][a-z_\d]*[a-z\d]$")?, name: Some("snake_case".to_string())},
            "upper_snake_case" => rule::Convention{regex: Regex::new(r"^[A-Z][A-Z_\d]*$")?, name: Some("upper_snake_case".to_string())},
            "camel_case" => rule::Convention{regex: Regex::new(r"^[a-z][A-Za-z\d]*$")?, name: Some("camel_case".to_string())},
            "pascal_case" => rule::Convention{regex: Regex::new(r"^[A-Z][A-Za-z\d]*$")?, name: Some("pascal_case".to_string())},
            convention => rule::Convention{regex: Regex::new(convention)?, name: None},
        };

        return Ok(Rule{
            pattern: Glob::new(&rule_to_parse.pattern.unwrap_or("*".to_string()))?.compile_matcher(),
            kind: rule_to_parse.kind.unwrap_or(Kind::Any),
            convention,
        });
    }).collect::<Result<Vec<_>, FlintError>>()?;

    return Ok(rules);
}


fn main() -> Result<(), FlintError> {

    let config_data = fs::read_to_string(".flint.sane")?;
    let decoded: Config = sane::from_str(&config_data)?;
    let rules = parse_config(decoded)?;

    let matches = App::new(clap::crate_name!())
        .author(clap::crate_authors!())
        .version(clap::crate_version!())
        .about(clap::crate_description!())
        .arg(
            Arg::with_name("files")
                .multiple(true)
                .default_value(".")
                .help("Input files")
        )
        .arg(
            Arg::with_name("verbose")
            .short("v")
            .long("verbose")
            .help("Display all processed files")
        )
        .get_matches();

    let is_verbose = matches.is_present("verbose");

    let mut ret_err = false;
    matches
        .values_of("files")
        .expect("error opening files")
        .collect::<Vec<_>>()
        .iter()
        .for_each(|file| {
            // for each file provided as CLI argument
            Walk::new(file)
                .filter_map(|entry| entry.ok()) // skip erroneous entries
                .for_each(|entry| {
                     // for each file or directory found while walking
                    let path =  entry.path();
                    if let Some(filestem) = path.file_stem() {
                        if let Some(filename) = path.file_name() {
                            let filestem = filestem.to_str().expect("error unwraping osStr");
                            let filename = filename.to_str().expect("error unwraping osStr");
                            let mut file_matched = false;
                            for rule in &rules {
                                if rule.pattern.is_match(filename) {
                                    if let Some(file_type) = entry.file_type() {
                                        if file_type.is_dir() && rule.kind == Kind::File {
                                            continue;
                                        } else if file_type.is_file() && rule.kind == Kind::Directory {
                                            continue;
                                        }
                                    }
                                    if !rule.convention.regex.is_match(filestem) {
                                        file_matched = true;
                                        if is_verbose {
                                            let convention_name =
                                                if let Some(ref name) = rule.convention.name {
                                                    format!(" ({})", name)
                                                } else { "".to_string() };
                                            println!("{} does not match {}{}",
                                                entry.path().display(),
                                                rule.convention.regex.as_str(),
                                                convention_name,
                                            );
                                        } else {
                                            println!("{}", entry.path().display());
                                        }
                                        ret_err = true;
                                    }
                                }
                            }
                            // display file if it didn't match but `flint` was calld with `-v`
                            if !file_matched && is_verbose {
                                println!("{}", entry.path().display());
                            }
                        }
                    }
                })
        });

    return match ret_err {
        true => Err(FlintError::FoundIssues),
        false => Ok(()),
    };
}
