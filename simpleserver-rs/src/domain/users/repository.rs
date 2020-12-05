use super::entities::User;
use crate::errors::Error;
use async_trait::async_trait;
use sqlx::{Pool, Postgres};

// We add Sync + Send in order to be mebeded as a Trait object
#[async_trait]
pub trait UsersRepository: Sync + Send {
    async fn create_user(&self, db: &Pool<Postgres>, user: &User) -> Result<(), Error>;
    async fn find_all_users(&self, db: &Pool<Postgres>) -> Result<Vec<User>, Error>;
}
