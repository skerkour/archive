package main

// Truncate the given float64 to 6 numbers after the dot
func Truncate(x float64) (truncated float64) {
	return float64(int(x*1000000)) / 1000000
}

// Returns the absolute value of the given float64
func Abs(x float64) (abs float64) {
	if x >= 0 {
		return x
	} else {
		return -x
	}
}

// Returns the sqaure root of the given float64, truncated to 6 numbers after the dot
func Sqrt(x float64) (sqrt float64) {
	z := 100.0
	DELTA := 0.0000001

	step := func() float64 {
		return z - (z*z-x)/(2*z)
	}

	for zz := step(); Abs(zz-z) > DELTA; {
		z = zz
		zz = step()
	}

	return Truncate(z)
}
