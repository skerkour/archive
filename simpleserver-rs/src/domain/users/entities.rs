use juniper::GraphQLObject;
use serde::{Deserialize, Serialize};

#[derive(sqlx::FromRow, Debug, Deserialize, Serialize, GraphQLObject)]
pub struct User {
    pub name: String,
    pub age: i32,
}
