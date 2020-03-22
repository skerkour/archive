use phaser_core::{
    error::PhaserError,
    scanner::{findings, BaseModule, HostModule, ModuleName, ReportV1, Target, TargetKind},
};
use std::process::Command;

pub struct Cname {}

impl BaseModule for Cname {
    fn name(&self) -> ModuleName {
        return ModuleName::DomainCname;
    }

    fn description(&self) -> String {
        return String::from("retrieve CNAME record data");
    }

    fn author(&self) -> String {
        return String::from("Sylvain Kerkour <sylvain@kerkour.fr>");
    }

    fn version(&self) -> String {
        return String::from("0.1.0");
    }
}

// TODO: remove unwraps
impl HostModule for Cname {
    fn run(&self, _: &ReportV1, target: &Target) -> Result<findings::ModuleResult, PhaserError> {
        if let TargetKind::Ip = target.kind {
            return Ok(findings::ModuleResult::None);
        };

        let dig_output = Command::new("dig")
            .arg("+short")
            .arg("CNAME")
            .arg(&target.host)
            .output()?;
        let output = String::from_utf8_lossy(&dig_output.stdout).to_string();

        let output = output.trim().to_string();
        if !output.is_empty() {
            return Ok(findings::ModuleResult::Domain(output));
        }

        return Ok(findings::ModuleResult::None);
        // let mut errs = vec!();
        // let mut ret = None;
        // // Google dns server, 8.8.8.8:53
        // let dns_server_address = SocketAddr::new(IpAddr::V4(Ipv4Addr::new(8, 8, 8, 8)), 53);

        // match target.kind {
        //     TargetKind::Ip => { return (ret, errs); },
        //     _ => {}, // if domain, continue
        // }

        // let conn = UdpClientConnection::new(dns_server_address).unwrap();
        // let client = SyncClient::new(conn);

        // // Specify the name, note the final '.' which specifies it's an FQDN
        // let name = Name::from_str(&target.host).unwrap();

        // // NOTE: see 'Setup a connection' example above
        // // Send the query and get a message response, see RecordType for all supported options
        // let response: DnsResponse = client.query(&name, DNSClass::IN, RecordType::CNAME).unwrap();

        // // Messages are the packets sent between client and server in DNS, DnsResonse's can be
        // //  dereferenced to a Message. There are many fields to a Message, It's beyond the scope
        // //  of these examples to explain them. See trust_dns::op::message::Message for more details.
        // //  generally we will be interested in the Message::answers
        // let answers: &[Record] = response.answers();

        // // Records are generic objects which can contain any data.
        // //  In order to access it we need to first check what type of record it is
        // //  In this case we are interested in A, IPv4 address
        // if answers.len() > 0 {
        //     if let &RModuleResult::CNAME(ref name) = answers[0].rdata() {
        //         ret = Some(findings::ModuleResult::Domain(name.to_utf8()));
        //     }
        //     // TODO: else, log weird data
        // }
    }
}

#[cfg(test)]
mod tests {
    use phaser_core::scanner::BaseModule;

    #[test]
    fn module_name() {
        let module = super::Cname {};
        assert_eq!("domain/cname", module.name().to_string());
    }
}
