mod api;
mod domain;
mod errors;
mod repository;
mod server;
mod service;

use crate::service::Service;
use errors::Error;
use repository::Repository;
use sqlx::postgres::PgPoolOptions;
use std::env;
// use log::{info, error};
use actix_web::{
    // error::ErrorBadRequest,
    web,
    // web::{self, BytesMut},
    App as ActixApp,
    HttpServer,
};
use api::App;
use api::{graphql, rest};
use std::sync::Arc;

#[actix_web::main]
async fn main() -> Result<(), Error> {
    std::env::set_var("RUST_LOG", "actix_web=info");

    let db = PgPoolOptions::new()
        .max_connections(100)
        .connect(&env::var("DATABASE_URL")?)
        .await?;

    let users_repo = Repository::new();

    let users_service = Service::new(db, Box::new(users_repo));
    // let server = Server::new(Box::new(users_service));

    let app = Arc::new(App {
        users_service: Box::new(users_service),
    });
    let graphql_schema = Arc::new(graphql::schema());

    // server.run();

    env_logger::init();
    let endpoint = "127.0.0.1:8081";

    println!("Starting server at: {:?}", endpoint);
    HttpServer::new(move || {
        ActixApp::new()
            .data(app.clone())
            .data(graphql_schema.clone())
            .service(web::resource("/").route(web::get().to(rest::index)))
            .service(web::resource("/graphiql").route(web::get().to(graphql::graphiql)))
            .service(web::resource("/graphql").route(web::post().to(graphql::graphql)))
            .service(web::resource("/users").route(web::get().to(rest::users)))
            // default
            .default_service(
                // 404 for GET request
                web::resource("").to(rest::p404),
            )
    })
    .bind(endpoint)?
    .run()
    .await?;

    Ok(())
}
