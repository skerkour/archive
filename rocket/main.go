package main

import (
	"github.com/bloom42/rocket/commands"
	"github.com/bloom42/rz-go"
	"github.com/bloom42/rz-go/log"
)

func main() {
	log.Logger = log.Config(rz.Formatter(rz.FormatterCLI()), rz.Level(rz.InfoLevel))
	if err := commands.RocketCmd.Execute(); err != nil {
		log.Fatal(err.Error(), nil)
	}
}
