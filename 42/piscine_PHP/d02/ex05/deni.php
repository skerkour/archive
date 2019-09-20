#!/usr/bin/env php
<?php
$lol = "LOL\n";

if ($argc === 3) {

	if (!file_exists($argv[1])) {
		exit(-42);
	}

if (($file = fopen($argv[1], "r")) == FALSE) {
	exit(-42);
}

$keys = fgets($file);
$keys = trim($keys);
$keys = explode(";", $keys);
if (in_array($argv[2], $keys) === FALSE) {
	exit(-42);
}

$index = array_search($argv[2], $keys);

$data = array();
while (($line = fgets($file))) {
	$line = trim($line);
	$data[] = $line;
}
fclose($file);

$i = 0;
foreach ($keys as $key) {
	${$key.$var} = array();
	foreach ($data as $line) {
		$line = explode(";", $line);
		${$key.$var}[$line[$index]] = $line[$i];
	}
	$i++;
}



while (42) {
	echo "Entrez votre commande: ";
	$str = fgets(STDIN);
	if (feof(STDIN) === TRUE) {
		echo "\n";
		break;
	}
	eval($str);
}




}

?>
