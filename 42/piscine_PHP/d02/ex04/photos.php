#!/usr/bin/env php
<?php

if ($argc > 1) {

	$arr = parse_url($argv[1]);
	if (array_key_exists("host", $arr)) {
		$host = $arr["host"];
		mkdir($host);
		if(($page = file_get_contents($argv[1])) == FALSE) {
			echo "Error : invalid URL\n";
			exit(-42);
		}
		preg_match_all('/<img[^>]+>/i',$page, $imgs);
		foreach($imgs[0] as $tag) {
			preg_match_all('/(src)="([^"]*)"/i',$tag, $img[$tag]);
		}
		if (!$img) {
			exit(0);
		}
		foreach ($img as $i) {
			if (!preg_match("/^https?:/", $i[2][0])) {
				$i[2][0] = $argv[1].$i[2][0];
			}
			$ch = curl_init($i[2][0]);
			$fp = fopen("./".$host."/".basename($i[2][0]), "w");
			curl_setopt($ch, CURLOPT_FILE, $fp);
			curl_setopt($ch, CURLOPT_HEADER, 0);
			curl_exec($ch);
			curl_close($ch);
			fclose($fp);
		}
	} else {
		echo "Error : invalid url\n";
	}
}

?>
