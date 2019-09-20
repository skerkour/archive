package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestTruncate(t *testing.T) {
	var expected float64
	var value float64

	expected = 0.151515
	value = Truncate(10.0 / 66.0)
	assert.Equal(t, expected, value, "They should be equal")

	expected = 3.333333
	value = Truncate(10.0 / 3.0)
	assert.Equal(t, expected, value, "They should be equal")

	expected = 3.01
	value = Truncate(3.01)
	assert.Equal(t, expected, value, "They should be equal")

	expected = 0.0
	value = Truncate(0.0)
	assert.Equal(t, expected, value, "They should be equal")

	expected = -0.00042
	value = Truncate(-0.00042)
	assert.Equal(t, expected, value, "They should be equal")
}

func TestAbs(t *testing.T) {
	var expected float64
	var value float64

	expected = 2.42
	value = Abs(2.42)
	assert.Equal(t, expected, value, "They should be equal")

	expected = 2.42
	value = Abs(-2.42)
	assert.Equal(t, expected, value, "They should be equal")

	expected = 3.0
	value = Abs(-3)
	assert.Equal(t, expected, value, "They should be equal")
}

func TestSqrt(t *testing.T) {

}
