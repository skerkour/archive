<?php

function checkExistingUserAuth($arr, $user) {
	$i = 0;
	foreach ($arr as $usr) {
		if ($usr["login"] === $user) {
			return $i;
		}
		$i++;
	}
	return -1;
}

function auth($login, $passwd) {
	if (($users = file_get_contents("../private/passwd")) === FALSE) {
		return FALSE;
	}
	$users = unserialize($users);
	if (($pos = checkExistingUserAuth($users, $login)) < 0) {
		return FALSE;
	}
	if (hash("whirlpool", $passwd) != $users[$pos]["passwd"]) {
		return FALSE;
	}
	return TRUE;
}

?>
