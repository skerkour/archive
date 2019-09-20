<?php

	$content = file_get_contents("list.csv");
	$lines = explode("\n", $content);
	$liness = array();
	$i = 0;
	foreach ($lines as $line) {
		if ($i != 0) {
			$note = explode(";", $line);
			$liness[$note[0]] = $note[1];
		}
		$i++;
	}
	echo json_encode($liness);
?>
