<?php

include_once "app/Request.php";
include_once "app/Response.php";
include_once "app/Logger.php";
include_once "config/database.php";

class App
{
  public $routers = array();
  public $logger;
  public $request_time_start;
  public $request_time_end;
  public $db;

  function __construct() {
    global $DB_DSN, $DB_USER, $DB_PASSWORD;

    $this->logger = new Logger();
    try {
      $this->db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
      $this->db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    } catch (PDOException $e) {
      echo $this->error_handler(500, "", "error connecting to the database : ".$e);
      exit();
    }
  }

  function process() {
    header_remove("X-Powered-By");

    $this->request_time_start = microtime(true);

    $done = false;
    $req = new Request($this);
    $res = new Response();

    foreach ($this->routers as $router) {
      if ($router->process_request($req, $res) == true) {
        $done = true;
      }
    }

    if ($done == false) {
      $this->not_found();
    }
    $this->request_time_end = microtime(true);
    $this->logger->log_request(http_response_code(), $req->url,
      ($this->request_time_start - $this->request_time_end));
  }

  function not_found() {
    echo $this->error_handler(404, "", "");
  }

  function error_handler($code, $informations, $log_informations) {
    $err = array("code" => $code,
      "informations" => $informations,
      "message" => ""
    );

    switch ($code) {
    case 400:
      $err["message"] = "Bad Request";
      break;
    case 401:
      $err["message"] = "Unauthorized";
      break;
    case 403:
      $err["message"] = "Forbidden";
      break;
    case 404:
      $err["message"] = "Not Found";
      break;
    case 409:
      $err["message"] = "Conflict";
      break;
    default:
      $err["code"] = 500;
      $err["message"] = "Internal Server Error";
      break;
    }

    $this->logger->log_error($err["code"], $log_informations);

    header("Content-Type: application/json");
    http_response_code($err["code"]);
    return json_encode($err);
  }

  function add_router($router) {
    array_push($this->routers, $router);
  }

  function gen_uuid() {
    return sprintf( '%04x%04x-%04x-%04x-%04x-%04x%04x%04x',
        // 32 bits for "time_low"
        mt_rand( 0, 0xffff ), mt_rand( 0, 0xffff ),

        // 16 bits for "time_mid"
        mt_rand( 0, 0xffff ),

        // 16 bits for "time_hi_and_version",
        // four most significant bits holds version number 4
        mt_rand( 0, 0x0fff ) | 0x4000,

        // 16 bits, 8 bits for "clk_seq_hi_res",
        // 8 bits for "clk_seq_low",
        // two most significant bits holds zero and one for variant DCE1.1
        mt_rand( 0, 0x3fff ) | 0x8000,

        // 48 bits for "node"
        mt_rand( 0, 0xffff ), mt_rand( 0, 0xffff ), mt_rand( 0, 0xffff )
    );
  }

  function random_string($length = 32) {
    $alphabet = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~!@#$%^&*()_+';
    $alphabet_length = strlen($alphabet);
    $str = '';
    for ($i = 0; $i < $length; $i++) {
        $str .= $alphabet[rand(0, $alphabet_length - 1)];
    }
    return $str;
  }

  function hash_password($password, $salt) {
    $options = [
      'cost' => 10,
      'salt' => $salt,
    ];
    return password_hash(hash('sha512', $password), PASSWORD_BCRYPT, $options);
  }

  function antixss($input) {
    strip_tags($input);
    $new = htmlspecialchars($input, ENT_QUOTES);
    return $new;
  }

}

?>
