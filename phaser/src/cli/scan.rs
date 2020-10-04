use clap::ArgMatches;
use phaser_core::scanner::{ConfigV1, ReportV1, Target};
use std::process;
use std::str::FromStr;
use uuid::Uuid;

// TODO
pub fn run(matches: &ArgMatches) -> Result<(), String> {
    if let Some(targets) = matches.values_of("targets") {
        let targets = targets.map(|target| Target::from_str(target)).collect();

        match targets {
            Ok(targets) => {
                let random_report_id = Uuid::new_v4();
                let random_scan_id = Uuid::new_v4();
                let data_folder = format!("reports/{}", random_report_id);
                let config = ConfigV1 {
                    data_folder,
                    assets_folder: "assets".to_string(),
                };
                let mut report = ReportV1::new(config, random_report_id, random_scan_id, targets);
                phaser_scanner::run_report(&mut report);
            }
            Err(err) => {
                println!("{:?}", err);
                process::exit(1);
            }
        }
    }
    Ok(())
}
