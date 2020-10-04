use failure::Fail;
use sane::de;

#[derive(Debug, Fail)]
pub enum FlintError {
    #[fail(display="Io: {}", 0)]
    Io(std::io::Error),

    #[fail(display="Sane: {}", 0)]
    SaneDe(de::Error),

    #[fail(display="Globset: {}", 0)]
    Globset(globset::Error),

    #[fail(display="Regex: {}", 0)]
    Regex(regex::Error),

    #[fail(display="Found issues")]
    FoundIssues,
}


impl std::convert::From<std::io::Error> for FlintError {
    fn from(err: std::io::Error) -> Self {
        FlintError::Io(err)
    }
}

impl std::convert::From<de::Error> for FlintError {
    fn from(err: de::Error) -> Self {
        FlintError::SaneDe(err)
    }
}

impl std::convert::From<globset::Error> for FlintError {
    fn from(err: globset::Error) -> Self {
        FlintError::Globset(err)
    }
}

impl std::convert::From<regex::Error> for FlintError {
    fn from(err: regex::Error) -> Self {
        FlintError::Regex(err)
    }
}
