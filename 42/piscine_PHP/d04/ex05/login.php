<?php
session_start();

include 'auth.php';

if (!$_POST["login"] || !$_POST["passwd"] || !auth($_POST["login"], $_POST["passwd"])) {
	echo "ERROR\n<br /><a href='index.html'>back</a>\n";
} else {
	$_SESSION["logged_as_user"] = $_POST["login"];
?>
	<html><body>
		<iframe name="chat" src="chat.php" width="100%" height="550px"></iframe>
		<iframe name="speak" src="speak.php" width="100%" height="50px"></iframe>
	</body></html>
<?php

}

?>
