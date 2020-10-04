package main

import (
	stdlog "log"
	"os"

	"gitlab.com/bloom42/bitflow/cmd"
)

func main() {
	stdlog.SetOutput(os.Stderr)
	cmd.Execute()
}
