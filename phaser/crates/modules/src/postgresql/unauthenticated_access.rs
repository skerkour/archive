use phaser_core::{
    error::PhaserError,
    scanner::{findings, BaseModule, ModuleName, PortModule, ReportV1, Target},
};
use postgres::{Connection, TlsMode};

pub struct UnauthenticatedAccess {}

impl BaseModule for UnauthenticatedAccess {
    fn name(&self) -> ModuleName {
        return ModuleName::PostgresqlUnauthenticatedAccess;
    }

    fn description(&self) -> String {
        return "Check for PostgreSQL Unauthenticated Access".to_string();
    }

    fn author(&self) -> String {
        return "Sylvain Kerkour <sylvain@kerkour.fr>".to_string();
    }

    fn version(&self) -> String {
        return "0.1.0".to_string();
    }
}

impl PortModule for UnauthenticatedAccess {
    fn run(
        &self,
        _: &ReportV1,
        target: &Target,
        port: &findings::Port,
    ) -> Result<findings::ModuleResult, PhaserError> {
        if port.http || port.https {
            return Ok(findings::ModuleResult::None);
        }

        let url = format!("postgres://postgres@{}:{}", &target.host, &port.id);

        let ret = match Connection::connect(url.clone(), TlsMode::None) {
            Ok(_) => findings::ModuleResult::Url(findings::Url { url }),
            _ => findings::ModuleResult::None,
        };

        return Ok(ret);
    }
}

#[cfg(test)]
mod tests {
    use phaser_core::scanner::BaseModule;

    #[test]
    fn module_name() {
        let module = super::UnauthenticatedAccess {};
        assert_eq!(
            "postgresql/unauthenticated-access",
            module.name().to_string()
        );
    }
}
