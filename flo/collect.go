package flo

import (
	"reflect"
)

// Collect is used to collect the chainable's data
func (c *Chainable) Collect() interface{} {
	return reflect.ValueOf(c.data).Interface()
}
