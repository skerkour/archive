<?php

include_once "site/header.php";
include_once "site/footer.php";

function site_register($req, $res) {
  site_header($req, $res);
?>
<form action="">
  Email : <br/>
  <input type="email" name="email" id="register_email" />
  <br/>
  Username : <br/>
  <input type="text" name="username" id="register_username" />
  <br/>
  Password : <br>
  <input type="password" name="password" id="register_password" />
  <br/><br/>
  <button type="button" onClick="app.register()">Register</button>
</form>

<a href="/login">Login</a>
<?php
  site_footer($req, $res);
}

?>
