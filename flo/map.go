package flo

import (
	"reflect"
)

// Map manipulates an iteratee and transforms it to another type.
func (c *Chainable) Map(mapFunc interface{}) *Chainable {
	funcValue := reflect.ValueOf(mapFunc)
	arrValue := reflect.ValueOf(c.data)
	funcType := funcValue.Type()
	resultSliceType := reflect.SliceOf(funcType.Out(0))
	length := arrValue.Len()
	resultSlice := reflect.MakeSlice(resultSliceType, length, length)

	for i := 0; i < length; i++ {
		result := funcValue.Call([]reflect.Value{arrValue.Index(i), reflect.ValueOf(i)})[0]
		resultSlice.Index(i).Set(result)
	}

	c.data = resultSlice.Interface()

	return c
}
