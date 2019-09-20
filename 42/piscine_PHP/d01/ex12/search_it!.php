#!/usr/bin/env php
<?php

$len = count($argv);
if ($len > 2) {
	$key = $argv[1];
	$len--;
	$slen = strlen($key);
	while ($len > 1) {
		if (strpos($argv[$len], $key) === 0 && $argv[$len][$slen] === ':') {
			echo substr($argv[$len], strrpos($argv[$len], ":") + 1)."\n";
			$len = 0;
		}
		$len--;
	}
}

?>
