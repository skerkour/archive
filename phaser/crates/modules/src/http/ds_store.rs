use phaser_core::{
    error::PhaserError,
    scanner::{findings, BaseModule, ModuleName, PortModule, ReportV1, Target},
};

pub struct DsStore {}

impl BaseModule for DsStore {
    fn name(&self) -> ModuleName {
        return ModuleName::HttpDsStore;
    }

    fn description(&self) -> String {
        return "Check for .DS_Store file disclosure".to_string();
    }

    fn author(&self) -> String {
        return "Sylvain Kerkour <sylvain@kerkour.fr>".to_string();
    }

    fn version(&self) -> String {
        return "0.1.0".to_string();
    }
}

// TODO: error handling not found
impl PortModule for DsStore {
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

        let url = format!("{}://{}:{}/.DS_Store", &protocol, &target.host, &port.id);
        let mut body = reqwest::get(&url)?;

        let mut buf: Vec<u8> = vec![];
        body.copy_to(&mut buf)?;

        if is_ds_store(&buf) {
            return Ok(findings::ModuleResult::Url(findings::Url { url }));
        }

        return Ok(findings::ModuleResult::None);
    }
}

fn is_ds_store(content: &[u8]) -> bool {
    if content.len() < 8 {
        return false;
    }

    let signature = [0x0, 0x0, 0x0, 0x1, 0x42, 0x75, 0x64, 0x31];

    return content[0..8] == signature;
}

#[cfg(test)]
mod tests {
    use phaser_core::scanner::BaseModule;

    #[test]
    fn module_name() {
        let module = super::DsStore {};
        assert_eq!("http/ds-store", module.name().to_string());
    }

    #[test]
    fn is_dotenv() {
        let body = "Aswswswsw";
        let body2 = [
            0x00, 0x00, 0x00, 0x01, 0x42, 0x75, 0x64, 0x31, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00,
            0x08, 0x0,
        ];

        assert_eq!(false, super::is_ds_store(body.as_bytes()));
        assert_eq!(true, super::is_ds_store(&body2));
    }
}
