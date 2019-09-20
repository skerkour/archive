<?php

function route_post_auth_password($req, $res) {
  $data = json_decode(file_get_contents('php://input'));
  if (!$data) {
    echo $req->app->error_handler(400, "Request cannot be empty", "");
    exit();
  }

  if (!property_exists($data, "email") || $data->email == "") {
    echo $req->app->error_handler(400, "email is missing", "");
    exit();
  }

  if (!property_exists($data, "password") || $data->password == "") {
    echo $req->app->error_handler(400, "password is missing", "");
    exit();
  }

  $email = $data->email;
  $password = $data->password;

  $sql = "SELECT * FROM users WHERE email = :email";
  $sth = $req->app->db->prepare($sql);
  $sth->execute(array(":email" => $email));
  $results = $sth->fetchAll();

  if (count($results) == 0) {
    echo $req->app->error_handler(404, "email not found", "");
    exit();
  }

  $result = $results[0];
  if ($result["password"] != $req->app->hash_password($password, $result["salt"])) {
    echo $req->app->error_handler(401, "Invalid password", "")."\n";
    exit();
  }

  if ($result["verified"] == false) {
    echo $req->app->error_handler(401, "You should verify your account before trying to log in", "")."\n";
    exit();
  }

  $token = $req->app->gen_uuid();
  $stmt = $req->app->db->prepare("UPDATE users SET token = ? WHERE id = ?");
  $stmt->execute(array($token, $result["id"]));

  $resp = array(
    "id" => $result["uid"],
    "username" => $result["username"],
    "token" => $token,
  );
  echo $res->json($resp);
}

?>
