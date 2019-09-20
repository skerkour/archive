<?php

if (isset($_GET["id"]) && is_numeric($_GET["id"])) {
	$content = file_get_contents("list.csv");
	$lines = explode("\n", $content);
	$result = "";
	$i = 0;
	foreach ($lines as $line) {
		if ($i != 0) {
			$liner = explode(";", $line);
			if ($liner[0] != $_GET["id"] && $line != "")
				$result = $result.$line."\n";
		} else
			$result = $result.$line."\n";
		$i++;
	}
	file_put_contents("list.csv", $result);
}
?>
