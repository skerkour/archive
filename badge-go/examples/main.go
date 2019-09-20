package main

import (
	"flag"
	"fmt"

	"github.com/bloom42/badge-go"
)

var (
	subject = flag.String("subject", "hello", "Badge subject")
	status  = flag.String("status", "world", "Badge status")
	color   = flag.String("color", "blue", "Badge color")
)

func main() {
	flag.Parse()

	badge, err := badge.RenderBytes(*subject, *status, badge.Color(*color))
	if err != nil {
		panic(err)
	}
	fmt.Printf("%s", badge)
}
