<?php

class Logger
{
  private $file_logs;
  private $file_error_logs;

  function __construct() {
    $this->file_logs = fopen("logs.txt", "a+");
    $this->file_error_logs = fopen("error_logs.txt", "a+");
  }

  function log_error($code, $informations) {
     fwrite($this->file_error_logs, "[".$code."] ".$informations."\n");
  }

  function log_request($code, $URI, $time) {
     fwrite($this->file_logs, "[".$code."] ".$time." ms - ".$URI."\n");
  }

}

?>
