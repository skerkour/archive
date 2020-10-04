use phaser_core::{
    log::macros::*,
    scanner::{findings, BaseModule, HostModule, Report, ReportV1},
};
use phaser_modules;
use std::fs;

pub fn run_report(report: &mut ReportV1) {
    // create direcotry
    fs::create_dir_all(&report.config.data_folder).expect("error creating report/{id} folder");

    let targets = report.targets.clone();
    // for each target
    for (i, target) in targets.iter().enumerate() {
        // can ports
        let ports_module = phaser_modules::Ports {};
        let ports_module_findings = ports_module.run(report, &target);
        let data = match &ports_module_findings {
            Ok(ref finding_data) => finding_data.clone(),
            Err(ref err) => findings::ModuleResult::Err(err.to_string()),
        };
        report.targets[i]
            .findings
            .insert(ports_module.name(), ports_module.finding(data));

        // then host modules
        let host_modules = phaser_modules::get_host_modules();
        host_modules.iter().for_each(|module| {
            info!("starting module: {}", module.name());
            let data = match module.run(report, &target) {
                Ok(finding_data) => finding_data,
                Err(err) => findings::ModuleResult::Err(err.to_string()),
            };
            report.targets[i]
                .findings
                .insert(module.name(), module.finding(data));
            info!("module {} completed", module.name());
        });

        // and finally, for each open port of the target, ports modules
        let port_modules = phaser_modules::get_port_modules();
        if let Ok(findings::ModuleResult::Ports(ref ports)) = ports_module_findings {
            ports.iter().for_each(|port| {
                port_modules.iter().for_each(|module| {
                    info!("starting module: {}", module.name());
                    let data = match module.run(report, &target, &port) {
                        Ok(finding_data) => finding_data,
                        Err(err) => findings::ModuleResult::Err(err.to_string()),
                    };
                    report.targets[i]
                        .findings
                        .insert(module.name(), module.finding(data));
                    info!("module {} completed", module.name());
                });
            });
        }
    }

    let path = format!("{}/report.json", &report.config.data_folder);
    // TODO: handle error
    let shell = Report::V1(report.clone());
    fs::write(
        path,
        serde_json::to_string_pretty(&shell).expect("serializing scan to json"),
    )
    .expect("error saving report.json");
}
