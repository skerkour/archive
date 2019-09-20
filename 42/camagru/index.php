<?php
include_once "app/App.php";
include_once "app/Router.php";

include_once "api/routes/get_hello_friend.php";
include_once "api/routes/post_users.php";
include_once "api/routes/post_auth_password.php";

include_once "site/login.php";
include_once "site/register.php";
include_once "site/home.php";
include_once "site/index.php";

if (preg_match("/\.(?:png|jpg|jpeg|gif|ico|js|css)$/",
  $_SERVER["REQUEST_URI"])) {
  return false;
}

$app = new App();
$logger = new Logger();

$router = new Router();
$router->get("/^(\/|\/index\.php)$/", "site_index");
$router->get("/^\/login$/", "site_login");
$router->get("/^\/register$/", "site_register");
$router->get("/^\/home$/", "site_home");


$api_router = new Router();

// GET /api
$api_router->get("/^\/api$/", "route_get_hello_friend");

// POST /api/users
$api_router->post("/^\/api\/users$/", "route_post_users");

// POST /auth/password
$api_router->post("/^\/api\/auth\/password$/", "route_post_auth_password");

$app->add_router($router);
$app->add_router($api_router);

$app->process();

?>
