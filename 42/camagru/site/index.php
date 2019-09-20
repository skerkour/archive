<?php

function site_index($req, $res) {
  if (false && is_authenticated($req)) {
    site_home($req, $res);
  } else {
    $res->redirect("/login");
  }

}

?>
