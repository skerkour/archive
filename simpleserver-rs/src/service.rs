use crate::domain::users::entities::User;
use crate::domain::users::repository::UsersRepository;
use crate::domain::users::service::{CreateUserInput, UsersService};
use async_trait::async_trait;
use sqlx::{Pool, Postgres};

// #[derive(Clone, Debug)]
pub struct Service {
    db: Pool<Postgres>,
    repo: Box<dyn UsersRepository>,
}

impl Service {
    pub fn new(db: Pool<Postgres>, repository: Box<dyn UsersRepository>) -> Service {
        Service {
            db,
            repo: repository,
        }
    }
}

#[async_trait]
impl UsersService for Service {
    async fn create_user(&self, input: CreateUserInput) -> anyhow::Result<User> {
        println!("usersService/create_user");
        let user = User {
            name: input.name,
            age: input.age,
        };

        self.repo.create_user(&self.db, &user).await?;

        Ok(user)
    }

    async fn find_all_users(&self) -> anyhow::Result<Vec<User>> {
        println!("usersService/find_all_users");
        let users = self.repo.find_all_users(&self.db).await?;
        Ok(users)
    }
}
