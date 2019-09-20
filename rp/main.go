package main

import (
	"github.com/bloom42/astro-go"
	"github.com/bloom42/astro-go/log"
)

func main() {
	log.Config(
		astro.SetFormatter(astro.CLIFormatter{}),
	)
	if err := rootCmd.Execute(); err != nil {
		log.Fatal(err.Error())
	}
}
