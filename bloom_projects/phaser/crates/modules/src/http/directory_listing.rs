use phaser_core::{
    error::PhaserError,
    scanner::{findings, BaseModule, ModuleName, PortModule, ReportV1, Target},
};
use regex::Regex;

pub struct DirectoryListing {}

impl BaseModule for DirectoryListing {
    fn name(&self) -> ModuleName {
        return ModuleName::HttpDirectoryListing;
    }

    fn description(&self) -> String {
        return "Check for enabled directory listing, which often leak informationr".to_string();
    }

    fn author(&self) -> String {
        return "Sylvain Kerkour <sylvain@kerkour.fr>".to_string();
    }

    fn version(&self) -> String {
        return "0.1.0".to_string();
    }
}

// TODO: error handling not found
impl PortModule for DirectoryListing {
    fn run(
        &self,
        _: &ReportV1,
        target: &Target,
        port: &findings::Port,
    ) -> Result<findings::ModuleResult, PhaserError> {
        let protocol = if port.http {
            "http"
        } else if port.https {
            "https"
        } else {
            ""
        };

        if protocol == "" {
            return Ok(findings::ModuleResult::None);
        }

        let url = format!("{}://{}:{}/", &protocol, &target.host, &port.id);
        let body = reqwest::get(&url)?.text()?;

        if is_directory_listing(&body) {
            return Ok(findings::ModuleResult::Url(findings::Url { url }));
        }

        return Ok(findings::ModuleResult::None);
    }
}

fn is_directory_listing(file_content: &str) -> bool {
    let re =
        Regex::new(r"<title>Index of .*</title>").expect("compiling http/directory-listing regexp");
    return re.is_match(file_content);
}

#[cfg(test)]
mod tests {
    use phaser_core::scanner::BaseModule;

    #[test]
    fn module_name() {
        let module = super::DirectoryListing {};
        assert_eq!("http/directory-listing", module.name().to_string());
    }

    #[test]
    fn is_directory_listing() {
        let body = "lol lol lol ol ol< LO> OL  <title>Index of kerkour.fr</title> sdsds";
        let body2 = "lol lol lol ol ol< LO> OL  <tle>Index of kerkour.fr</title> sdsds";
        let body3 = "";
        let body4 = "lol lol lol ol ol< LO> OL  <title>Index</title> sdsds";

        assert_eq!(true, super::is_directory_listing(&body));
        assert_eq!(false, super::is_directory_listing(&body2));
        assert_eq!(false, super::is_directory_listing(&body3));
        assert_eq!(false, super::is_directory_listing(&body4));
    }
}
