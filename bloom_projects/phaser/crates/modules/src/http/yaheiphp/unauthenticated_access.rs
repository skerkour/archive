use phaser_core::{
    error::PhaserError,
    scanner::{findings, BaseModule, ModuleName, PortModule, ReportV1, Target},
};

pub struct UnauthenticatedAccess {}

impl BaseModule for UnauthenticatedAccess {
    fn name(&self) -> ModuleName {
        return ModuleName::HttpYaheiphpUnauthenticatedAccess;
    }

    fn description(&self) -> String {
        return "Check for Yahei (http://www.yahei.net) Unauthenticated Access".to_string();
    }

    fn author(&self) -> String {
        return "Sylvain Kerkour <sylvain@kerkour.fr>".to_string();
    }

    fn version(&self) -> String {
        return "0.1.0".to_string();
    }
}

// TODO: error handling not found
impl PortModule for UnauthenticatedAccess {
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

        // TODO: also check tz_e.php
        let url = format!("{}://{}:{}/proberv.php", &protocol, &target.host, &port.id);
        let body = reqwest::get(&url)?.text()?;

        if body.contains(r#"<title>Yahei-PHP"#) {
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
        let module = super::UnauthenticatedAccess {};
        assert_eq!(
            "http/yaheiphp/unauthenticated-access",
            module.name().to_string()
        );
    }
}
