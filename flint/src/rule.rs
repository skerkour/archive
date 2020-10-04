use serde::{Serialize, Deserialize};
use globset::{GlobMatcher};
use regex::Regex;


#[derive(Clone, Debug, Deserialize, Serialize)]
pub struct ConfigRule {
    pub pattern: Option<String>,
    #[serde(rename = "type")]
    pub kind: Option<Kind>,
    pub convention: String,
}

#[derive(Clone, Debug)]
pub struct Rule {
    pub pattern: GlobMatcher,
    pub kind: Kind,
    pub convention: Convention,
}

#[derive(Clone, Debug)]
pub struct Convention {
    pub regex: Regex,
    pub name: Option<String>,
}

#[derive(Clone, Copy, Debug, Deserialize, PartialEq, Serialize)]
pub enum Kind {
    #[serde(rename = "file")]
    File,
    #[serde(rename = "directory")]
    Directory,
    #[serde(rename = "any")]
    Any,
}
