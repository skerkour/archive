<?php

function site_header($req, $res) {
?>
<!DOCTYPE html>
<html>
  <head>
    <title>Camagru</title>
      <script type="text/javascript" src="site/assets/js/app.js"></script>
      <link rel="stylesheet" type="text/css" href="site/assets/css/style.css">
  </head>
  <body>
<?php
  if ($req-> path != "/login" && $req-> path != "/register" && $req-> path != "/reset-password") {

    if (!isset($_COOKIE["id"]) || !$_COOKIE["token"]) {
      $res->redirect("/login");
      exit(); 
    }

    $uid = $_COOKIE["id"];
    $token = $_COOKIE["token"];

    $sql = "SELECT * FROM users WHERE uid = :uid AND token = :token";
    $sth = $req->app->db->prepare($sql);
    $sth->execute(array(":uid" => $uid, ":token" => $token));
    $results = $sth->fetchAll();

    if (count($results) !== 1) {
      $res->redirect("/login");
      exit(); 
    }
?>
  <div id="header_bar">
    <span id="header_bar_logout" class="clickable" onClick="app.logout()" >Logout</span>
  </div>
<?php
  }

?>
  <div id="alert_box" class="hidden">
    <span id="alert_box_content"></span>
    <span class="clickable" id="alert_box_cross" onClick="app.alertBoxHide()" >X</span>
  </div>


<?php
}

?>
