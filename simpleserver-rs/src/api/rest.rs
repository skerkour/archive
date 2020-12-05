use super::App;
use actix_web::{
    // error::ErrorBadRequest,
    web,
    // web::{self, BytesMut},
    HttpResponse,
};
use std::collections::HashMap;
use std::sync::Arc;

pub async fn index(_app: web::Data<Arc<App>>) -> HttpResponse {
    let mut res = HashMap::new();
    res.insert("hello", "world");

    HttpResponse::Ok().json(res)
}

pub async fn users(app: web::Data<Arc<App>>) -> HttpResponse {
    match app.clone().users_service.find_all_users().await {
        Ok(users) => HttpResponse::Ok().json(users),
        Err(err) => {
            println!("api/users: {}", err);
            HttpResponse::InternalServerError().body("Internal error")
        }
    }
}

/// 404 handler
pub async fn p404() -> HttpResponse {
    let mut res = HashMap::new();
    res.insert("error", "route not found");
    HttpResponse::NotFound().json(res)
}
