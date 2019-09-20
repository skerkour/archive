package flo

import (
	"fmt"
	"reflect"
)

// Reverse transforms a collection: the first element will become the last,
// the second element will become the second to last, etc.
func (c *Chainable) Reverse() *Chainable {
	value := reflect.ValueOf(c.data)
	valueType := value.Type()
	kind := value.Kind()

	if kind == reflect.Array || kind == reflect.Slice {
		length := value.Len()
		resultSlice := reflect.MakeSlice(valueType, length, length)

		j := 0
		for i := length - 1; i >= 0; i-- {
			resultSlice.Index(j).Set(value.Index(i))
			j++
		}

		c.data = resultSlice.Interface()
		return c
	}

	panic(fmt.Sprintf("Type %s is not supported by Reverse", valueType.String()))
}
