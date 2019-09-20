#!/usr/bin/env php
<?php

function ft_is_sort($arr) {
	$len = count($arr);
	$i = 0;
	while ($i < $len - 1) {
		if (strcmp($arr[$i + 1], $arr[$i]) < 0) {
			return FALSE;
		}
		$i++;
	}
	return TRUE;
}

?>
