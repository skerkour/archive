<?php

include_once "site/header.php";
include_once "site/footer.php";

function site_login($req, $res) {
  site_header($req, $res);
?>
<form action="">
  Email : <br/>
  <input type="email" name="email" id="login_email"/>
  <br/>
  Password : <br>
  <input type="password" name="password" id="login_password"/>
  <br/><br/>
  <button type="button" onClick="app.login()">Log in</button>
</form>
<a href="/register">Register</a>

<?php
  site_footer($req, $res);
}

?>
