#!/usr/bin/env php
<?php

function ft_split($str) {
	$str = preg_split("/(\t|\s)+/", $str);
	$str = preg_split("/^(\t|\s)+/", implode($str, " "));
	return preg_split("/(\t|\s)+$/", implode($str));
}

if (count($argv) > 1) {
	$strs = ft_split($argv[1]);
	echo $strs[0];
	echo "\n";
}

?>
