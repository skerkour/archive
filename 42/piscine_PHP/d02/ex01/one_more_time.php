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

if ($argc > 1) {
	$argv[1][0] = toLower($argv[1][0]);
	if (preg_match("/^(lundi|mardi|mercredi|jeudi|vendredi|samedi|dimanche|) [0-3]?[0-9] (Janvier|Fevrier|Mars|Avril|Mai|Juin|Juillet|Aout|Septembre|Octobre|Novembre|Decembre|janvier|fevrier|mars|avril|mai|juin|juillet|aout|septembre|octobre|novembre|decembre) [0-9]{4} ([01]?[0-9]|2[0-3])(:[0-5][0-9]){2}$/", $argv[1]) === 1) {
		$strs = explode(" ", strToLowerr($argv[1]));
		$days = array("dimanche","lundi","mardi","mercredi","jeudi","vendredi","samedi");
		$months = array("","janvier","fevrier","mars","avril","mai","juin","juillet","août","septembre","octobre","novembre","decembre");
		$hours = explode(":", $strs[4]);
		date_default_timezone_set('Europe/Paris');
		echo mktime($hours[0], $hours[1], $hours[2], array_search($strs[2], array_keys($months)), $strs[1], $strs[3]);
		echo "\n";
	} else {
		echo "Wrong Format\n";
	}
}
?>
