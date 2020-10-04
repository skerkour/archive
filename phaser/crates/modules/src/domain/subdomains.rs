use phaser_core::{
    error::PhaserError,
    scanner::{findings, BaseModule, HostModule, ModuleName, ReportV1, Target, TargetKind},
};
use postgres::{Connection, TlsMode};

pub struct Subdomains {}

impl BaseModule for Subdomains {
    fn name(&self) -> ModuleName {
        return ModuleName::DomainSubdomains;
    }

    fn description(&self) -> String {
        return String::from("Find subdomains for a given domain");
    }

    fn author(&self) -> String {
        return String::from("Sylvain Kerkour <sylvain@kerkour.fr>");
    }

    fn version(&self) -> String {
        return String::from("0.1.0");
    }
}

impl HostModule for Subdomains {
    fn run(&self, _: &ReportV1, target: &Target) -> Result<findings::ModuleResult, PhaserError> {
        let mut domains = vec![];

        if let TargetKind::Ip = target.kind {
            return Ok(findings::ModuleResult::None);
        };

        let conn = Connection::connect("postgres://guest@crt.sh:5432/certwatch", TlsMode::None)?;

        let subdomains_pattern = format!("%.{}", &target.host);

        let index = match subdomains_pattern.find('%') {
            Some(i) => i,
            None => 0,
        };
        let index_reverse = match subdomains_pattern
            .chars()
            .rev()
            .collect::<String>()
            .find('%')
        {
            Some(i) => i,
            None => 0,
        };

        let query = if index < index_reverse {
            "SELECT DISTINCT ci.NAME_VALUE as domain
			FROM certificate_identity ci
			WHERE reverse(lower(ci.NAME_VALUE)) LIKE reverse(lower($1))"
        } else {
            "SELECT DISTINCT ci.NAME_VALUE as domain
            FROM certificate_identity ci
            WHERE lower(ci.NAME_VALUE) LIKE lower($1)"
        };

        let rows = conn.query(query, &[&subdomains_pattern])?;
        for row in &rows {
            domains.push(row.get(0));
        }

        return Ok(findings::ModuleResult::Domains(domains));
    }
}

#[cfg(test)]
mod tests {
    use phaser_core::scanner::BaseModule;

    #[test]
    fn module_name() {
        let module = super::Subdomains {};
        assert_eq!("domain/subdomains", module.name().to_string());
    }
}
