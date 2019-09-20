<?php
session_start();

if ($_GET["login"] && $_GET["submit"] && $_GET["submit"] == "OK") {
	$_SESSION["login"] = $_GET["login"];
}
if ($_GET["passwd"] && $_GET["submit"] && $_GET["submit"] == "OK") {
	$_SESSION["passwd"] = $_GET["passwd"];
}

?>
<html><body>
<form action="index.php" method="GET">
Identifiant: <input type="text" name="login" value="<?php if ($_SESSION["login"]) echo $_SESSION["login"]; ?>" />
	<br />
	Mot de passe: <input type="password" name="passwd" value="<?php if ($_SESSION["passwd"]) echo $_SESSION["passwd"]; ?>" /> <br />
	<input type="submit" value="OK" name="submit" <br />
</form>
</body></html>
