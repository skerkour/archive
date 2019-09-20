#!/usr/bin/env php
<?php

if ($argc > 1) {
	if (($file = fopen($argv[1], "r")) == FALSE) {
		exit(-42);
	}
	$data = array();
	while (($str = fgets($file))) {
		$t = trim(fgets($file));
		$word = trim(fgets($file));
		$emp = fgets($file);
		$data[$t] = $word;
	}
	fclose($file);
	ksort($data);

	$i = 1;
	$len = count($data);
	foreach($data as $key => $val) {
		echo $i."\n";
		echo $key."\n";
		echo $val."\n";
		if ($i != $len) {
			echo "\n";
		}
		$i++;
	}
}

?>
