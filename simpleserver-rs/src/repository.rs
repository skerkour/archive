use crate::domain::users::entities::User;
use crate::domain::users::repository::UsersRepository;
use crate::errors::Error;
use async_trait::async_trait;
use sqlx::{Pool, Postgres};

pub struct Repository {}

impl Repository {
    pub fn new() -> Repository {
        Repository {}
    }
}

#[async_trait]
impl UsersRepository for Repository {
    async fn create_user(&self, db: &Pool<Postgres>, user: &User) -> Result<(), Error> {
        println!("UsersRepository/create_user");
        sqlx::query("INSERT INTO users (name, age) VALUES ($1, $2)")
            .bind(&user.name)
            .bind(&user.age)
            .execute(db)
            .await?;
        Ok(())
    }

    async fn find_all_users(&self, db: &Pool<Postgres>) -> Result<Vec<User>, Error> {
        println!("UsersRepository/find_all_users");
        let users = sqlx::query_as::<_, User>("SELECT * FROM users")
            .fetch_all(db)
            .await?;
        Ok(users)
    }
}
