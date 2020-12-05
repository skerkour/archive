pub mod graphql;
pub mod rest;

use crate::domain::users::service::UsersService;
pub struct App {
    pub users_service: Box<dyn UsersService>,
}
