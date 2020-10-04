use phaser_core::{
    error::PhaserError,
    scanner::{findings, BaseModule, ModuleName, PortModule, ReportV1, Target},
};

pub struct OpenRegistration {}

impl BaseModule for OpenRegistration {
    fn name(&self) -> ModuleName {
        return ModuleName::HttpGitlabOpenRegistration;
    }

    fn description(&self) -> String {
        return "Check if the gitlab instance is open to registrations".to_string();
    }

    fn author(&self) -> String {
        return "Sylvain Kerkour <sylvain@kerkour.fr>".to_string();
    }

    fn version(&self) -> String {
        return "0.1.0".to_string();
    }
}

// TODO: error handling not found
impl PortModule for OpenRegistration {
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

        let url = format!("{}://{}:{}", &protocol, &target.host, &port.id);
        let body = reqwest::get(&url)?.text()?;

        if body.to_lowercase().contains("ref:") && body.contains("Register") {
            return Ok(findings::ModuleResult::Url(findings::Url { url }));
        }

        return Ok(findings::ModuleResult::None);
    }
}

#[cfg(test)]
mod tests {
    use phaser_core::scanner::BaseModule;

    #[test]
    fn module_name() {
        let module = super::OpenRegistration {};
        assert_eq!("http/gitlab/open-registration", module.name().to_string());
    }
}
