#!/usr/bin/env php
<?php

function printError() {
	echo "Incorrect Parameters\n";
	exit(-42);
}

function removeSpaces($str) {
	$str = str_replace(' ', '', $str);
	return str_replace("\t", '', $str);
}

if (count($argv) == 4) {
	$oprnd1 = removeSpaces($argv[1]);
	$oprtor = removeSpaces($argv[2]);
	$oprnd2 = removeSpaces($argv[3]);

	switch ($oprtor) {
		case "+":
			$ret = $oprnd1 + $oprnd2;
			break;
		case "-":
			$ret = $oprnd1 - $oprnd2;
			break;
		case "*":
			$ret = $oprnd1 * $oprnd2;
			break;
		case "/":
			$ret = $oprnd1 / $oprnd2;
			break;
		case "%":
			$ret = $oprnd1 % $oprnd2;
			break;
	}
	echo $ret."\n";
} else {
	printError();
}

?>
