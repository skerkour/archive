package flo

import (
	"testing"
)

func TestMap(t *testing.T) {
	nums := []int{1, 2, 3, 4}
	expectedNums := []int{2, 4, 6, 8}
	nums = From(nums).Map(func(x, i int) int {
		return x * 2
	}).Collect().([]int)

	for i, expected := range expectedNums {
		if expected != nums[i] {
			t.Errorf("Map was incorrect, got: %d, want: %d at index %d.", nums[i], expected, i)
		}
	}
}
