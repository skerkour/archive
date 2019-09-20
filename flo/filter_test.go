package flo

import (
	"testing"
)

func TestFilter(t *testing.T) {
	nums := []int{1, 2, 3, 4}
	expectedNums := []int{1, 2}
	nums = From(nums).Filter(func(s int) bool {
		return s <= 2
	}).Collect().([]int)

	for i, expected := range expectedNums {
		if expected != nums[i] {
			t.Errorf("Map was incorrect, got: %d, want: %d at index %d.", nums[i], expected, i)
		}
	}
}
