<?php

class Response
{

  function code($code) {
    http_response_code($code);
  }

  function json($input) {
    header('Content-Type: application/json');
    return json_encode($input, JSON_UNESCAPED_SLASHES);
  }

  function redirect($url) {
    header("Location: ".$url);
  }

}

?>
