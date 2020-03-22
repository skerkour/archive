use phaser_core::{
    error::PhaserError,
    scanner::{findings, BaseModule, ModuleName, PortModule, ReportV1, Target},
};

pub struct HeadDisclosure {}

impl BaseModule for HeadDisclosure {
    fn name(&self) -> ModuleName {
        return ModuleName::HttpGitheadDisclosure;
    }

    fn description(&self) -> String {
        return "Check for .git/HEAD file disclosure".to_string();
    }

    fn author(&self) -> String {
        return "Sylvain Kerkour <sylvain@kerkour.fr>".to_string();
    }

    fn version(&self) -> String {
        return "0.1.0".to_string();
    }
}

// TODO: error handling not found
impl PortModule for HeadDisclosure {
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

        if protocol.is_empty() {
            return Ok(findings::ModuleResult::None);
        }

        let url = format!("{}://{}:{}/.git/HEAD", &protocol, &target.host, &port.id);
        let body = reqwest::get(&url)?.text()?;

        if is_head_file(&body) {
            return Ok(findings::ModuleResult::Url(findings::Url { url }));
        }

        return Ok(findings::ModuleResult::None);
    }
}

fn is_head_file(content: &str) -> bool {
    return Some(0) == content.to_lowercase().trim().find("ref:");
}

#[cfg(test)]
mod tests {
    use phaser_core::scanner::BaseModule;

    #[test]
    fn module_name() {
        let module = super::HeadDisclosure {};
        assert_eq!("http/git/head-disclosure", module.name().to_string());
    }

    #[test]
    fn is_head_file() {
        let body = r#"ref: refs/heads/master"#;
        let body2 = r#"ref: refs/heads/heroku"#;
        let body3 = "lol lol lol ol ol< LO> OL  <tle>Index of kerkour.fr</title> sdsds";

        assert_eq!(true, super::is_head_file(body));
        assert_eq!(true, super::is_head_file(body2));
        assert_eq!(false, super::is_head_file(body3));
    }
}
