<?php

class Request
{
  public $url;
  public $app;
  public $ip;
  public $path;
  public $params;
  public $protocol;
  public $method;
  public $data = array();


  function __construct($app) {
    $this->url = "http://$_SERVER[HTTP_HOST]$_SERVER[REQUEST_URI]";
    $this->app = $app;
    $this->ip = $_SERVER["REMOTE_ADDR"];
    $this->path = parse_url($this->url, PHP_URL_PATH);
    $this->params = $_GET;
    $this->protocol = "http";
    $this->method = $_SERVER["REQUEST_METHOD"];

  }

}

?>
