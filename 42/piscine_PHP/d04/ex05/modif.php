<?php

function checkExistingUser($arr, $user) {
	$i = 0;
	foreach ($arr as $usr) {
		if ($usr["login"] === $user) {
			return $i;
		}
		$i++;
	}
	return -1;
}


if (!$_POST["submit"] || $_POST["submit"] != "OK" || !$_POST["login"] || !$_POST["oldpw"] || !$_POST["newpw"]) {
	echo "ERROR\n";
} else {
	if (($users = file_get_contents("../private/passwd")) == FALSE) {
		$users = array();
	} else {
		$users = unserialize($users);
	}
	if (($pos = checkExistingUser($users, $_POST["login"])) < 0) {
		echo "ERROR\n";
	} else {
		if (hash("whirlpool", $_POST["oldpw"]) != $users[$pos][3]) {
			echo "ERROR\n";
		} else {
			$arr["login"] = $_POST["login"];
			$arr["passwd"] = hash("whirlpool", $_POST["newpw"]);
			$users[$pos] = $arr;
			file_put_contents("../private/passwd", serialize($users));
			echo "OK\n";
			header("Location: index.html");
		}
	}
}

?>
