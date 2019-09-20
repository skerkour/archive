<?php

function route_post_users($req, $res) {
  $data = json_decode(file_get_contents('php://input'));
  if (!$data) {
    echo $req->app->error_handler(400, "Request cannot be empty", "");
    exit();
  }

  if (!property_exists($data, "email") || $data->email == "") {
    echo $req->app->error_handler(400, "email is missing", "");
    exit();
  }

  if (!property_exists($data, "username") || $data->username == "") {
    echo $req->app->error_handler(400, "username is missing", "");
    exit();
  }

  if (!property_exists($data, "password" || $data->password == "")) {
    echo $req->app->error_handler(400, "password is missing", "");
    exit();
  }

  if (strlen($password) < 8) {
    echo $req->app->error_handler(400, "password is too short", "");
    exit();
  }  else if (!ctype_alnum($username)) {
    echo $req->app->error_handler(400, "username should only contains alphanuric characters", "");
    exit();
  }

  $salt = $req->app->random_string();
  $username = mb_strtolower($data->username);
  $email = mb_strtolower($data->email);
  $password = $data->password;
  $uid = $req->app->gen_uuid();

  $sql = "SELECT * FROM users WHERE username = :username OR email = :email";
  $sth = $req->app->db->prepare($sql);
  $sth->execute(array(":username" => $username, ":email" => $email));
  $results = $sth->fetchAll();
  if (count($results) > 0) {
    foreach ($results as $result) {
      if ($result["email"] == $email) {
        echo $req->app->error_handler(409, "email already registrated", "");
      } else if ($result["username"] == $username) {
        echo $req->app->error_handler(409, "username already registrated", "");
      }
    }
    exit();
  } else if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
    echo $req->app->error_handler(400, "Inavlid email", $email." : invalid email");
    exit();

  }
    $stmt = $req->app->db->prepare("INSERT INTO users (uid, username, email, password, salt)
      VALUES (?, ?, ?, ?, ?)");
    $salt = $req->app->random_string();
    $stmt->execute(array($uid, $username, $email,
      $req->app->hash_password($password, $salt), $salt));

    $res->code(201);
    $res->json(array("message" => "User successfully created"));
}

?>
