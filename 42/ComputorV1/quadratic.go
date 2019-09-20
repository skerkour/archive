package main

import (
	"errors"
	"math"
)

type Complex128 struct {
	real float64
	imag float64
}

func (n Complex128) IsNaN() bool {
	if math.IsNaN(n.real) {
		return true
	} else {
		return false
	}
}

type Quadratic struct {
	a float64
	b float64
	c float64
}

// Returns the discriminant of the quadratic equation b^2 - 4ac
func (eq Quadratic) Discriminant() (discr float64) {
	return (eq.b * eq.b) - (4 * eq.a * eq.c)
}

func (eq Quadratic) Solve() (x1, x2 Complex128, discr float64, err error) {
	discr = eq.Discriminant()

	if eq.a == 0 {
		return x1, x2, discr, errors.New("a can't be 0")
	}

	if discr > 0 {
		x1r := (-eq.b + Sqrt(discr)) / (2 * eq.a)
		x1 = Complex128{x1r, 0}
		x2r := (-eq.b - Sqrt(discr)) / (2 * eq.a)
		x2 = Complex128{x2r, 0}

	} else if discr == 0 {
		xr := -eq.b / (2 * eq.a)
		x1 = Complex128{xr, 0}
		x2 = x1

	} else {
		xr := -eq.b / (2 * eq.a)
		x1i := Sqrt(-discr) / (2 * eq.a)
		x2i := -(Sqrt(-discr) / (2 * eq.a))
		x1 = Complex128{xr, x1i}
		x2 = Complex128{xr, x2i}
	}

	return x1, x2, discr, nil
}
