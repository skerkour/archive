<?php

final class Dice {

	private $_n;

	function __construct(array $kwargs = array()) {

		if (array_key_exists("n", $kwargs))
			$this->_n = intval($kwargs["n"]);
		else
			$this->_n = 6;
	}

	public function throww() {
		return rand(1, $this->_n);
	}

}

?>
