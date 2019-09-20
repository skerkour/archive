package main

import (
	"github.com/astrocorp42/astroflow-go/log"
)

func main() {
	if err := rootCmd.Execute(); err != nil {
		log.Fatal(err.Error())
	}
}
