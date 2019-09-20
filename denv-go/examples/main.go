package main

import (
	"fmt"
	"os"

	"github.com/bloom42/denv-go"
)

func main() {
	os.Setenv("FIRST_NAME", "Sysy")
	denv.Init(denv.Env{
		"FIRST_NAME": "Sylvain",
		"LAST_NAME":  "Kerkour",
	})

	fmt.Println("FIRST_NAME:", os.Getenv("FIRST_NAME"))
	fmt.Println("LAST_NAME:", os.Getenv("LAST_NAME"))
}
