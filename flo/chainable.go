package flo

import (
	"reflect"
)

// Chainable is used to chain functions
type Chainable struct {
	t    reflect.Type
	data interface{}
}

// From create a new Chainble struct from an existing collection
func From(in interface{}) *Chainable {
	return &Chainable{
		t:    reflect.TypeOf(in),
		data: in,
	}
}
