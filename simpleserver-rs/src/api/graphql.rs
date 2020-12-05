use super::App;
use crate::domain::users::{entities::User, service};
use actix_web::{web, Error, HttpResponse};
use futures::channel::mpsc::channel;
use juniper::http::graphiql::graphiql_source;
use juniper::http::GraphQLRequest;
use juniper::FieldResult;
use std::sync::Arc;

pub type Schema = juniper::RootNode<'static, QueryResolver, Mutation, Subscription>;
pub fn schema() -> Schema {
    Schema::new(QueryResolver, Mutation, Subscription)
}

pub async fn graphiql() -> HttpResponse {
    let html = graphiql_source("http://127.0.0.1:8081/graphql", None);
    HttpResponse::Ok()
        .content_type("text/html; charset=utf-8")
        .body(html)
}

pub async fn graphql(
    schema: web::Data<Arc<Schema>>,
    app: web::Data<Arc<App>>,
    data: web::Json<GraphQLRequest>,
) -> Result<HttpResponse, Error> {
    let res = data.execute(&schema, &app).await;
    Ok(HttpResponse::Ok()
        .content_type("application/json")
        .json(res))
    // let res = web::block(move || {
    //     let res = data.execute(&schema, &app).await;
    //     Ok::<_, serde_json::error::Error>(serde_json::to_string(&res)?)
    // })
    // .await
    // .map_err(Error::from)?;

    // Ok(HttpResponse::Ok()
    //     .content_type("application/json")
    //     .body(res))
}

pub struct QueryResolver;

#[juniper::graphql_object(Context = App)]
impl QueryResolver {
    pub async fn users(app: &App) -> FieldResult<Vec<User>> {
        let users = app.users_service.find_all_users().await?;
        Ok(users)
    }
}

pub struct Subscription;

type CallsStream = std::pin::Pin<Box<dyn futures::Stream<Item = FieldResult<i32>> + Send>>;

#[juniper::graphql_subscription(Context = App)]
impl Subscription {
    pub async fn calls(ctx: &App) -> CallsStream {
        let (tx, rx) = channel(16);
        Box::pin(rx)
    }
}

#[derive(juniper::GraphQLInputObject, Debug)]
pub struct CreateUserInput {
    name: String,
    age: i32,
}
pub struct Mutation;
#[juniper::graphql_object(Context = App)]

impl Mutation {
    pub async fn create_user(app: &App, input: CreateUserInput) -> FieldResult<User> {
        let service_input = service::CreateUserInput {
            name: input.name,
            age: input.age,
        };
        let user = app.users_service.create_user(service_input).await?;
        Ok(user)
    }
}
