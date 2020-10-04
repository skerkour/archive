package main

import (
	"errors"
	"fmt"
	"os"
	"path/filepath"

	"gitlab.com/bloom42/appbox/calc"
	"gitlab.com/bloom42/appbox/help"
	"gitlab.com/bloom42/appbox/rss"
	"gitlab.com/bloom42/appbox/music"
	"gitlab.com/bloom42/appbox/install"
)

func main() {
	command := filepath.Base(os.Args[0])
	err := runAppbox(command, os.Args[1:])
	if err != nil {
		os.Exit(1)
	}
}

func runAppbox(command string, args []string) (err error) {
	switch command {
	case "appbox", "main":
		if len(args) > 0 {
			command := filepath.Base(args[0])
			err = runAppbox(command, args[1:])
		} else {
			err = help.Run(args)
		}
	case "calc":
		err = calc.Run(args)
	case "rss":
		err = rss.Run(args)
	case "music":
		err = music.Run(args)
	case "install":
		err = install.Run(args)
	default:
		errMsg := fmt.Sprintf("%s: command not found", command)
		fmt.Println(errMsg)
		err = errors.New(errMsg)
	}

	if err != nil {
		fmt.Println(err)
	}

	return
}
