<?php

set_include_path(".:..:");

include_once "database.php";
include_once "app/App.php";

$app = new App();

try {
  $dbh = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
  $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

  $dbh->exec("DROP DATABASE IF EXISTS camagru");
  $dbh->exec("CREATE DATABASE camagru");
  $dbh->exec("use camagru");
  $dbh->exec("CREATE TABLE users (
    id BIGINT NOT NULL AUTO_INCREMENT,
    uid VARCHAR(255) NOT NULL,
    username VARCHAR(255) NOT NULL,
    email VARCHAR(255) NOT NULL,
    password VARCHAR(255) NOT NULL,
    salt VARCHAR(255) NOT NULL,
    verified bool NOT NULL DEFAULT false,
    token VARCHAR(255) NOT NULL,
    PRIMARY KEY (id)
  )");
  $stmt = $dbh->prepare("INSERT INTO users (uid, username, email, password, salt, verified, token)
  VALUES (?, ?, ?, ?, ?, ?, ?)");
  $salt = $app->random_string();
  $stmt->execute(array($app->gen_uuid(), "admin", "admin@42.fr", $app->hash_password("admin42", $salt),
  $salt, true, $app->gen_uuid()));

  $dbh->exec("CREATE TABLE edited_pictures (
    id BIGINT NOT NULL AUTO_INCREMENT,
    uid VARCHAR(255) NOT NULL,
    name VARCHAR(255) NOT NULL,
    owner BIGINT NOT NULL,
    PRIMARY KEY (id),
    FOREIGN KEY (owner) REFERENCES users(id)
  )");

} catch (PDOException $e) {
    echo $e;
    exit();
}

?>
