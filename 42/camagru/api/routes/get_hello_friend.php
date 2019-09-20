<?php

function route_get_hello_friend($req, $res) {
  $rep = array();
  $rep["hello"] = "friend";
  $rep["req"] = $req;

  echo $res->json($rep);
}


?>
