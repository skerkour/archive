package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestDiscriminant(t *testing.T) {
	var q Quadratic
	var expected float64
	var value float64

	q = Quadratic{5, 2, 1}
	expected = -16
	value = q.Discriminant()
	assert.Equal(t, expected, value, "They should be equal")

	q = Quadratic{42, 21, 0}
	expected = 441
	value = q.Discriminant()
	assert.Equal(t, expected, value, "They should be equal")

	q = Quadratic{1, -6, 9}
	expected = 0
	value = q.Discriminant()
	assert.Equal(t, expected, value, "They should be equal")
}

func TestSolve(t *testing.T) {
	var q Quadratic
	var x1 Complex128
	var x2 Complex128

	q = Quadratic{1, -6, 9}
	x1, x2, _, _ = q.Solve()
	assert.Equal(t, x1.real, x2.real, "They should be equal (1 solution)")
	assert.Equal(t, x1.real, 3.0, "They should be equal")
	assert.Equal(t, x1.imag, 0.0, "They should be equal")

	q = Quadratic{5, 2, 1}
	x1, x2, _, _ = q.Solve()
	assert.NotEqual(t, x1, x2, "They should not be equal (2 complex solutions)")
	assert.Equal(t, x1.real, -0.2, "They should be equal")
	assert.Equal(t, x1.imag, 0.4, "They should be equal")
	assert.Equal(t, x2.real, -0.2, "They should be equal")
	assert.Equal(t, x2.imag, -0.4, "They should be equal")
}
