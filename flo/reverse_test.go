package flo

import (
	"testing"
)

func TestReverse(t *testing.T) {
	nums := []int{1, 2, 3, 4}
	expectedNums := []int{4, 3, 2, 1}
	nums = From(nums).Reverse().Collect().([]int)

	for i, expected := range expectedNums {
		if expected != nums[i] {
			t.Errorf("Map was incorrect, got: %d, want: %d at index %d.", nums[i], expected, i)
		}
	}
}
