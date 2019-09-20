#!/usr/bin/env php
<?php

function toLower($c) {
	$ascii = ord($c);
	if ($ascii >= 65 && $ascii <= 90) {
		$ascii = $ascii + 32;
	}
	return chr($ascii);
}

function strToLowerr($str) {
	$i = 0;
	while ($str[$i]) {
		$str[$i] = toLower($str[$i]);
		$i++;
	}
	return $str;
}

function ft_split($str) {
	return array_filter(explode(" ", implode(" ", array_filter(explode("\t", $str), "strlen"))), "strlen");
}

function cmpMod($a, $b) {
	$i = 0;
	$a = strToLowerr($a);
	$b = strToLowerr($b);
	if ($a == $b) {
		return 0;
	}
	while ($a[$i] && $a[$i] == $b[$i]) {
		$i++;
	}
	$a = ord($a[$i]);
	$b = ord($b[$i]);
	if ($a >= 48 && $a <= 57) {
		$a = $a + 1000;
	} else if ($a < 97 || $a > 122) {
		$a = $a + 10000;
	}
	if ($b >= 48 && $b <= 57) {
		$b = $b + 1000;
	} else if ($b < 97 || $b > 122) {
		$b = $b + 10000;
	}
	return $a < $b ? -1 : 1;
}

$i = 1;
$arr = array();

while ($i < $argc) {
	$strs = ft_split($argv[$i]);
	foreach ($strs as $str) {
		$arr[] = $str;
	}
	$i++;
}
usort($arr, "cmpMod");
$i = 0;
$len = count($arr);
while ($i < $len) {
	echo $arr[$i++]."\n";
}

?>
