<?php

class Color {

	public $red, $green, $blue;

	public static $verbose = FALSE;

	function __construct(array $kwargs) {

		if (array_key_exists('rgb', $kwargs)) {
			$this->red = ($kwargs['rgb'] & 0xff0000) >> 16;
			$this->green = ($kwargs['rgb'] & 0xff00) >> 8;
			$this->blue = ($kwargs['rgb'] & 0xff);
		} else {
			$this->red = $kwargs['red'] < 0 ? 0 : $kwargs['red'] > 255 ? 255 : $kwargs['red'];
			$this->green = $kwargs['green'] < 0 ? 0 : $kwargs['green'] > 255 ? 255 : $kwargs['green'];
			$this->blue = $kwargs['blue'] < 0 ? 0 : $kwargs['blue'] > 255 ? 255 : $kwargs['blue'];
		}
		if (self::$verbose === TRUE)
			printf("Color( red: %3d, green: %3d, blue: %3d ) constructed.\n", $this->red, $this->green, $this->blue);
	}

	function __destruct() {
		if (self::$verbose === TRUE)
			printf("Color( red: %3d, green: %3d, blue: %3d ) destructed.\n", $this->red, $this->green, $this->blue);
	}

	function __toString() {
		return sprintf("Color( red: %3d, green: %3d, blue: %3d )", $this->red, $this->green, $this->blue);
	}

	static function doc() {
		if (file_exists("Color.doc.txt"))
			return file_get_contents("Color.doc.txt");
	}


	public function add(Color $cpy) {
		return new Color(array(
			'red' => $this->red + $cpy->red,
			'green' => $this->green + $cpy->green,
			'blue' => $this->blue + $cpy->blue));
	}
	
	public function sub(Color $cpy) {
		return new Color(array(
			'red' => $this->red - $cpy->red,
			'green' => $this->green - $cpy->green,
			'blue' => $this->blue - $cpy->blue));
	}

	public function mult($x) {
		return new Color(array(
			'red' => $this->red * $x,
			'green' => $this->green * $x,
			'blue' => $this->blue * $x));
	}


}

?>
