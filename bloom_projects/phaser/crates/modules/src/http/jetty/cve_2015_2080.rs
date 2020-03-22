use phaser_core::{
    error::PhaserError,
    scanner::{findings, BaseModule, ModuleName, PortModule, ReportV1, Target},
};
use regex::Regex;

pub struct Cve2015_2080 {}

impl BaseModule for Cve2015_2080 {
    fn name(&self) -> ModuleName {
        return ModuleName::HttpJettyCve20152080;
    }

    fn description(&self) -> String {
        return "Check for CVE-2015-2080 (a.k.a. Jetleak)".to_string();
    }

    fn author(&self) -> String {
        return "Sylvain Kerkour <sylvain@kerkour.fr>".to_string();
    }

    fn version(&self) -> String {
        return "0.1.0".to_string();
    }
}

// TODO: error handling not found
impl PortModule for Cve2015_2080 {
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
        let res = reqwest::get(&url)?;

        if let Some(server) = res.headers().get("server") {
            let server = server.to_str()?.to_lowercase();
            let server = server.trim();
            let re = Regex::new(r"^jetty\(9\.2\.(3|4|5|6|7|8).*\)$|^jetty\(9\.3\.0\.(m0|m1).*\)$")?;

            if re.is_match(server) {
                return Ok(findings::ModuleResult::Url(findings::Url { url }));
            }
        }

        return Ok(findings::ModuleResult::None);
    }
}

#[cfg(test)]
mod tests {
    use phaser_core::scanner::BaseModule;

    #[test]
    fn module_name() {
        let module = super::Cve2015_2080 {};
        assert_eq!("http/jetty/cve-2015-2080", module.name().to_string());
    }
}
