<?php

function checkExistingUser($arr, $user) {
	foreach ($arr as $usr) {
		if ($usr["login"] === $user) {
			return TRUE;
		}
	}
	return FALSE;
}


if (!$_POST["submit"] || $_POST["submit"] != "OK" || !$_POST["login"] || !$_POST["passwd"]) {
	echo "ERROR\n";
} else {
	if (!file_exists("../private")) {
		mkdir("../private");
	}
	if (file_exists("../private/passwd")) {
		$users = unserialize(file_get_contents("../private/passwd"));
	}
	else {
		$users = array();
	}
	if (checkExistingUser($users, $_POST["login"])) {
		echo "ERROR\n";
	} else {
		$arr["login"] = $_POST["login"];
		$arr["passwd"] = hash("whirlpool", $_POST["passwd"]);
		$users[] = $arr;
		file_put_contents("../private/passwd", serialize($users));
		echo "OK\n";
	}
}

?>
