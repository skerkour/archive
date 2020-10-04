use clap::ArgMatches;
use phaser_core::scanner::BaseModule;

pub fn run(_: &ArgMatches) -> Result<(), String> {
    println!("{}", phaser_modules::Ports {}.name());

    phaser_modules::get_host_modules()
        .iter()
        .for_each(|module| {
            println!("{}", module.name());
        });

    phaser_modules::get_port_modules()
        .iter()
        .for_each(|module| {
            println!("{}", module.name());
        });

    Ok(())
}
