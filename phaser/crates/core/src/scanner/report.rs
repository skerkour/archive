use crate::info;

use crate::scanner::Target;
use serde::{Deserialize, Serialize};

#[derive(Clone, Debug, Deserialize, Serialize)]
pub enum Report {
    V1(ReportV1),
}

#[derive(Clone, Debug, Deserialize, Serialize)]
pub struct ReportV1 {
    pub id: uuid::Uuid,
    pub scan_id: uuid::Uuid,
    pub config: ConfigV1,
    pub targets: Vec<Target>,
    pub phaser_version: String,
}

#[derive(Clone, Debug, Default, Deserialize, Serialize)]
pub struct ConfigV1 {
    pub data_folder: String,
    pub assets_folder: String,
    // pub s3_client: S3Client,
}

impl ReportV1 {
    pub fn new(
        config: ConfigV1,
        id: uuid::Uuid,
        scan_id: uuid::Uuid,
        targets: Vec<Target>,
    ) -> ReportV1 {
        // fs::create_dir_all(&config.data_folder).expect("error creating scan's data folder");
        return ReportV1 {
            id,
            scan_id,
            targets,
            config,
            phaser_version: info::VERSION.to_string(),
        };
    }
}
