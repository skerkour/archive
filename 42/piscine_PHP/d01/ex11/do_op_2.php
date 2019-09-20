#!/usr/bin/env php
<?php

function printErrorParams() {
	echo "Incorrect Parameters\n";
	exit(-42);
}

function printErrorSyntax() {
	echo "Syntax Error\n";
	exit(-42);
}

function removeSpaces($str) {
	$str = str_replace(' ', '', $str);
	return str_replace("\t", '', $str);
}

function ft_do_op($str, $oprtor) {
	$arr = explode($oprtor, $str);
	if (count($arr) == 2) {
		if (!is_numeric($arr[0]) || !is_numeric($arr[1])) {
			printErrorSyntax();
		}
		$oprnd1 = $arr[0];
		$oprnd2 = $arr[1];
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
		exit(0);
	} else {
		printErrorSyntax();
	}
}

if (count($argv) == 2) {
	$str = removeSpaces($argv[1]);

	if ((bool)strpos($str, "+") && strrpos($str, "+") == strpos($str, "+")) {
		ft_do_op($str, "+");
	} else if ((bool)strpos($str, "-") && strrpos($str, "-") == strpos($str, "-")) {
		ft_do_op($str, "-");
	} else if ((bool)strpos($str, "*") && strrpos($str, "*") == strpos($str, "*")) {
		ft_do_op($str, "*");
	} else if ((bool)strpos($str, "/") && strrpos($str, "/") == strpos($str, "/")) {
		ft_do_op($str, "/");
	} else if ((bool)strpos($str, "%") && strrpos($str, "%") == strpos($str, "%")) {
		ft_do_op($str, "%");
	} else {
		printErrorSyntax();
	}

} else {
	printErrorParams();
}

?>
