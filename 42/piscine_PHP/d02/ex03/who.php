#!/usr/bin/env php
<?php

$content = file_get_contents("/var/run/utmpx");

$content = substr($content, 1256);
date_default_timezone_set('Europe/Paris');
$data = array();
$format = "A256Login/"
			."C4Id/"
			."A32Name/"
			."sPid/"
			."sTypee/"
			."IType/"
			."IDate/"
			."C256/"
			."C64/";
while ($content) {
	$arr = unpack($format, $content);
	$data[] = $arr;
	$content = substr($content, 628);
}
sort($data);
$i = 0;
$len = count($data);
while ($i < $len) {
	if ($data[$i]["Type"] == 7) {
		$len = strlen($data[$i]["Login"]);
		echo $data[$i]["Login"];
		while ($len++ < 9) {
			echo " ";
		}
		echo $data[$i]["Name"];
		$len = strlen($data[$i]["Name"]);
		while ($len++ < 9) {
			echo " ";
		}
		$data[$i]["Name"];
		echo date("M", $data[$i]["Date"])." ";
		printf("%2d ", intval(date("j H:i", $data[$i]["Date"])));
		echo date("H:i", $data[$i]["Date"])." \n";

	}
	
	$i++;
}

?>
