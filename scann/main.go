package main

import (
	"github.com/z0mbie42/scann/commands"
	"github.com/astroflow/astroflow-go"
	"github.com/astroflow/astroflow-go/log"
)

func main() {
	log.Config(
		astroflow.SetFormatter(astroflow.NewCLIFormatter()),
		astroflow.SetLevel(astroflow.InfoLevel),
	)
	if err := commands.RootCmd.Execute(); err != nil {
		log.Fatal(err.Error())
	}
}
