<?php
session_start();
date_default_timezone_set('Europe/Paris');

if ($_SESSION["logged_as_user"] && $_SESSION["logged_as_user"] != "") {

	if ($_POST["msg"]) {
		$msgs = file_get_contents("../private/chat", LOCK_EX);
		$file = fopen("../private/chat", "w");
		flock($file, LOCK_EX);
		$msgs = unserialize($msgs);
		$msg["login"] = $_SESSION["logged_as_user"];
		$msg["time"] = time();
		$msg["msg"] = $_POST["msg"];
		$msgs[] = $msg;
		file_put_contents("../private/chat", serialize($msgs));
		flock($file, LOCK_UN);
		fclose($file);
	}

?>
<form action="speak.php" method="POST">
	Msg: <input name="msg" value="" autofocus/><br />
	<input type="submit" value="OK" name="submit" /> <br />
</form>
<script langage="javascript">top.frames["chat"].location = "chat.php";</script>
<?php
} else {
	echo "ERROR\n";
}
?>
	fclose($file);
