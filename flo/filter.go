package flo

import (
	"reflect"
)

// Filter data according to a given function
func (c *Chainable) Filter(predicate interface{}) *Chainable {
	funcValue := reflect.ValueOf(predicate)
	funcType := funcValue.Type()
	if funcType.Out(0).Kind() != reflect.Bool {
		panic("Return argument should be a boolean")
	}

	arrValue := reflect.ValueOf(c.data)
	arrType := arrValue.Type()

	// Get slice type corresponding to array type
	resultSliceType := reflect.SliceOf(arrType.Elem())

	// MakeSlice takes a slice kind type, and makes a slice.
	resultSlice := reflect.MakeSlice(resultSliceType, 0, 0)

	for i := 0; i < arrValue.Len(); i++ {
		elem := arrValue.Index(i)
		result := funcValue.Call([]reflect.Value{elem})[0].Interface().(bool)
		if result {
			resultSlice = reflect.Append(resultSlice, elem)
		}
	}

	c.data = resultSlice.Interface()
	return c
}
