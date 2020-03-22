use phaser_core::{
    error::PhaserError,
    scanner::{findings, BaseModule, HostModule, ModuleName, ReportV1, Target, TargetKind},
};
use std::process::Command;

pub struct Spf {}

impl BaseModule for Spf {
    fn name(&self) -> ModuleName {
        return ModuleName::DomainSpf;
    }

    fn description(&self) -> String {
        return String::from("check if DNS SPF record is missing or insufficeient");
    }

    fn author(&self) -> String {
        return String::from("Sylvain Kerkour <sylvain@kerkour.fr>");
    }

    fn version(&self) -> String {
        return String::from("0.1.0");
    }
}

// TODO: only if root domain
impl HostModule for Spf {
    fn run(&self, _: &ReportV1, target: &Target) -> Result<findings::ModuleResult, PhaserError> {
        let mut is_spf_record_missing = true;

        if let TargetKind::Ip = target.kind {
            return Ok(findings::ModuleResult::None);
        };

        // first retrieve TXT records
        let dig_output = Command::new("dig")
            .arg("+short")
            .arg("TXT")
            .arg(&target.host)
            .output()?;
        let txt_output = String::from_utf8_lossy(&dig_output.stdout).to_string();

        let records: Vec<String> = txt_output
            .split('\n')
            .map(|record| record.trim().to_string())
            .filter(|record| !record.is_empty())
            .collect();

        let resolves = !records.is_empty();

        // for each record, check if DMARC data is present
        for record in &records {
            if record.to_lowercase().contains("v=spf1") {
                is_spf_record_missing = false;
                break;
            }
        }

        if is_spf_record_missing {
            return Ok(findings::ModuleResult::Spf(findings::domain::Spf {
                domain: target.host.clone(),
                records,
                resolves,
            }));
        }

        return Ok(findings::ModuleResult::None);
    }
}

#[cfg(test)]
mod tests {
    use phaser_core::scanner::BaseModule;

    #[test]
    fn module_name() {
        let module = super::Spf {};
        assert_eq!("domain/spf", module.name().to_string());
    }
}
