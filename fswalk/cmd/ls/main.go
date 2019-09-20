package main

import (
	"fmt"

	"github.com/z0mbie42/fswalk"
)

func main() {
	walker, _ := fswalk.NewWalker()
	filesc, _ := walker.Walk(".")
	for file := range filesc {
		fmt.Printf("%v\n", file)
	}
}
