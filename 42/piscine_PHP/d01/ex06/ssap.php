#!/usr/bin/env php
<?php

function ft_split($str) {
	return array_filter(explode(" ", implode(" ", array_filter(explode("\t", $str), "strlen"))), "strlen");
}

if (count($argv) > 1) {
	$arr = array();
	$i = 1;
	$len = count($argv);
	while ($i < $len) {
		$strs = ft_split($argv[$i]);
		foreach ($strs as $str) {
			$arr[] = $str;
		}
		$i++;
	}
	sort($arr);
	foreach ($arr as $str) {
		echo $str."\n";
	}
}

?>
