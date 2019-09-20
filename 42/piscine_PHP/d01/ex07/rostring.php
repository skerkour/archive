#!/usr/bin/env php
<?php

function ft_split($str) {
	return array_filter(explode(" ", $str), "strlen");
}

if (count($argv) > 1) {
	$arr = array();
	$i = 1;
	$len = count($argv);
	$arr = array_values(ft_split($argv[1]));
	$arr[] = $arr[0];
	array_shift($arr);
	$len = count($arr);
	$i = 0;
	while ($i < $len) {
		echo $arr[$i];
		if ($i != $len - 1) {
			echo " ";
		} else {
			echo "\n";
		}
		$i++;
	}
}

?>
