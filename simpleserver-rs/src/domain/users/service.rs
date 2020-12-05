use super::entities::User;
use crate::errors::Error;
use async_trait::async_trait;

#[async_trait]
pub trait UsersService: Sync + Send {
    async fn create_user(&self, input: CreateUserInput) -> Result<User, Error>;
    async fn find_all_users(&self) -> Result<Vec<User>, Error>;
}

pub struct CreateUserInput {
    pub name: String,
    pub age: i32,
}
