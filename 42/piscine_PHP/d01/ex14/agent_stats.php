#!/usr/bin/env php
<?php

Class User {
	var $totMarks;
	var $nMarks;
	var $mean;
	var $name;
	var $totMarksPeers;
	var $nMarksPeers;
	var $totMarksMouli;
	var $nMarksMouli;
	var $diff;

	function __construct() {
		$this->totMarks = 0;
		$this->totMarksPeers = 0;
		$this->nMarksPeers = 0;
		$this->totMarksMouli = 0;
		$this->nMarksMouli = 0;
		$this->nMarks = 0;
		$this->mean = 0;
		$this->name = "";
		$this->diff = 0;
	}

	function calcMean() {
		if ($this->nMarks != 0) {
			$this->mean = $this->totMarksPeers / $this->nMarksPeers;
		} else {
			$this->mean = 0;
		}
	}

	function calcDiff() {
		if ($this->nMarksPeers != 0 && $this->nMarksMouli != 0) {
			$meanMoul = $this->totMarksMouli / $this->nMarksMouli;
			$meanPeers = $this->totMarksPeers / $this->nMarksPeers;
			$this->diff = $meanPeers - $meanMoul;
		} else {
			$this->diff = 0;
		}
	}

}

$users = array();

$nMarksMouli = 0;
$totMarksMouli = 0;

if (count($argv) > 1) {
$str = fgets(STDIN);
while (($str = fgets(STDIN))) {
	$str = substr($str, 0, -1);
	$values = explode(";", $str);
	if (!array_key_exists($values[0], $users)) {
		$users[$values[0]] = new User();
		$users[$values[0]]->name = $values[0];
	}
	if (is_numeric($values[1])) {
		$users[$values[0]]->nMarks++;
		$users[$values[0]]->totMarks += $values[1];
		if (strcmp($values[2], "moulinette") === 0) {
			$users[$values[0]]->nMarksMouli++;
			$users[$values[0]]->totMarksMouli += $values[1];
		} else {
			$users[$values[0]]->nMarksPeers++;
			$users[$values[0]]->totMarksPeers += $values[1];
			$nMarksMouli++;
			$totMarksMouli	+= $values[1];
		}
	}
}

if (strcmp($argv[1], "moyenne") === 0) {
	echo $totMarksMouli / $nMarksMouli;
	echo "\n";
} else if (strcmp($argv[1], "moyenne_user") === 0) {
	ksort($users);
	foreach ($users as $user) {
		if ($user->nMarksPeers > 0) {
			$user->calcMean();
			echo $user->name.":".$user->mean."\n";
		}
	}
} else if (strcmp($argv[1], "ecart_moulinette") === 0) {
	ksort($users);
	foreach ($users as $user) {
		if ($user->nMarksMouli > 0 && $user->nMarksPeers > 0) {
			$user->calcDiff();
			echo $user->name.":".$user->diff."\n";
		}
	}
}

}

?>
