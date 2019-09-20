package flo

import (
	"reflect"
)

// Reduce takes a collection and reduces it to a single value using a reduction function
// (or a valid symbol) and an accumulator value.
func (c *Chainable) Reduce(reducer, acc interface{}) interface{} {
	funcValue := reflect.ValueOf(reducer)
	arrValue := reflect.ValueOf(c.data)
	accValue := reflect.ValueOf(acc)

	length := arrValue.Len()
	for i := 0; i < length; i++ {
		accValue = funcValue.Call([]reflect.Value{accValue, reflect.ValueOf(i), arrValue.Index(i)})[0]
	}
	return accValue.Interface()
}
