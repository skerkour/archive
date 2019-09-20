package flo

import (
	"testing"
)

func TestFrom(t *testing.T) {
	nums := []int{1, 2, 3, 4}
	chainable := From(nums)

	if chainable == nil {
		t.Errorf("chainable should not be null")
	}
}
