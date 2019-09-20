#!/usr/bin/env php
<?php

function toUpper($c) {
	$ascii = ord($c);
	if ($ascii >= 97 && $ascii <= 122) {
		$ascii = $ascii - 32;
	}
	return chr($ascii);
}

if ($argc > 1) {

$content = file_get_contents($argv[1]);
$len = strlen($content);
$i = 0;
$level = 0;
while ($i < $len) {
	if ($content[$i] == '<' && $content[$i + 1] == 'a') {
		$level++;
	} else  if ($content[$i] == '<' && $content[$i + 1] == '/' && $content[$i + 2] == 'a' && $content[$i + 3] == '>') {
		$level--;
	}
	if ($level > 0) {
		if ($content[$i] == 't' && $content[$i + 1] == 'i' && $content[$i + 2] == 't' && $content[$i + 3] == 'l' && $content[$i + 4] == 'e' && $content[$i + 5] == '=' && $content[$i + 6] == '"') {
			$i += 7;
			while ($content[$i] != '"') {
				$content[$i] = toUpper($content[$i]);
				$i++;
			}
		} else if ($content[$i] == '>') {
			$i++;
			while ($content[$i] != '<') {
				$content[$i] = toUpper($content[$i]);
				$i++;
			}
			$i--;
		}
	}
	$i++;
}
echo $content;

}

?>
