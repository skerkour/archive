<?php

abstract class IMiddleware
{
  abstract public function before_handler($req, $res);
  abstract public function after_handler($req, $res);

 }

?>
