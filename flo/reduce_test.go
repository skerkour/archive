package flo

import (
	"testing"
)

func TestReduce(t *testing.T) {
	nums := []int{1, 2, 3, 4}
	sum := From(nums).Reduce(func(acc, x, i int) int {
		return i + acc
	}, 0).(int)
	if sum != 10 {
		t.Errorf("Reduce was incorrect, got: %d, want: %d.", sum, 10)
	}
}
