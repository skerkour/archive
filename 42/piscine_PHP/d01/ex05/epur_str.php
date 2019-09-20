#!/usr/bin/env php
<?php

function ft_split($str) {
	return array_filter(explode(" ", implode(" ", array_filter(explode("\t", $str), "strlen"))), "strlen");
}

if (count($argv) == 2) {
	$strs = ft_split($argv[1]);
	$strs = array_values($strs);
	$len = count($strs);
	$i = 0;
	while ($i < $len) {
		echo $strs[$i];
		if ($i != $len - 1) {
			echo " ";
		}
		$i++;
	}
	echo "\n";
}
?>
