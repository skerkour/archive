use phaser_core::{
    error::PhaserError,
    scanner::{findings, BaseModule, HostModule, ModuleName, ReportV1, Target, TargetKind},
};
use serde::{Deserialize, Serialize};
use std::fs;

pub struct Takeover {}

impl BaseModule for Takeover {
    fn name(&self) -> ModuleName {
        return ModuleName::DomainTakeover;
    }

    fn description(&self) -> String {
        return "Check subdomain for takeover".to_string();
    }

    fn author(&self) -> String {
        return "Sylvain Kerkour <sylvain@kerkour.fr>".to_string();
    }

    fn version(&self) -> String {
        return "0.1.0".to_string();
    }
}

#[derive(Clone, Debug, Deserialize, Serialize)]
struct Provider {
    pub service: String,
    #[serde(rename = "cname")]
    pub cnames: Vec<String>,
    #[serde(rename = "fingerprint")]
    pub fingerprints: Vec<String>,
    pub nxdomain: bool,
}

impl HostModule for Takeover {
    fn run(&self, scan: &ReportV1, target: &Target) -> Result<findings::ModuleResult, PhaserError> {
        if let TargetKind::Ip = target.kind {
            return Ok(findings::ModuleResult::None);
        };

        // parse fingerprints
        let fingerprints_path =
            format!("{}/takeover_fingerprints.json", &scan.config.assets_folder);
        let fingerprints_data = fs::read_to_string(fingerprints_path)?;

        let providers: Vec<Provider> = serde_json::from_str(&fingerprints_data)?;

        let body = reqwest::get(&format!("http://{}", &target.host))?.text()?;

        for provider in &providers {
            for fingerprint in &provider.fingerprints {
                if body.contains(fingerprint) {
                    return Ok(findings::ModuleResult::Takeover(
                        findings::domain::Takeover {
                            service: provider.service.to_string(),
                        },
                    ));
                }
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
        let module = super::Takeover {};
        assert_eq!("domain/takeover", module.name().to_string());
    }
}
