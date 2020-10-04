use phaser_core::{
    error::PhaserError,
    scanner::{findings, BaseModule, HostModule, ModuleName, ReportV1, Target, TargetKind},
};
use std::process::Command;

pub struct Axfr {}

impl BaseModule for Axfr {
    fn name(&self) -> ModuleName {
        return ModuleName::DomainAxfr;
    }

    fn description(&self) -> String {
        return String::from("check if AXFR queries are enabled for each name server");
    }

    fn author(&self) -> String {
        return String::from("Sylvain Kerkour <sylvain@kerkour.fr>");
    }

    fn version(&self) -> String {
        return String::from("0.1.0");
    }
}

impl HostModule for Axfr {
    fn run(&self, _: &ReportV1, target: &Target) -> Result<findings::ModuleResult, PhaserError> {
        let mut data = vec![];

        if let TargetKind::Ip = target.kind {
            return Ok(findings::ModuleResult::None);
        };

        // first retrieve NS servers
        let dig_output = Command::new("dig")
            .arg("+short")
            .arg("NS")
            .arg(&target.host)
            .output()?;
        let ns_output = String::from_utf8_lossy(&dig_output.stdout).to_string();

        if ns_output.is_empty() {
            return Ok(findings::ModuleResult::None);
        }

        let ns_servers: Vec<&str> = ns_output.split(',').collect();

        // for each server, try AXFR DNS query
        for ns_server in ns_servers {
            let mut output = String::new();
            if let Ok(dig_output) = Command::new("dig")
                .arg("AXFR")
                .arg(&target.host)
                .arg(format!("@{}", ns_server))
                .output()
            {
                output = String::from_utf8_lossy(&dig_output.stdout).to_string()
            };
            if output.contains("XFR") && !output.contains("transfer failed") {
                data.push(findings::domain::Axfr {
                    server: ns_server.to_string(),
                    response: output,
                });
            }
        }

        if !data.is_empty() {
            return Ok(findings::ModuleResult::Axfr(data));
        }

        return Ok(findings::ModuleResult::None);
    }
}

#[cfg(test)]
mod tests {
    use phaser_core::scanner::BaseModule;

    #[test]
    fn module_name() {
        let module = super::Axfr {};
        assert_eq!("domain/axfr", module.name().to_string());
    }
}
