package commands

import (
	"bufio"
	"fmt"
	"os"
	"path/filepath"
	"regexp"
	"strings"

	"github.com/z0mbie42/scann/config"
	"github.com/astroflow/astroflow-go"
	"github.com/astroflow/astroflow-go/log"
	"github.com/spf13/cobra"
	"github.com/z0mbie42/fswalk"
	"sync"
)

var scannConfigPath string
var debug bool
var rootFormat string
var reg = regexp.MustCompile("(TODO|FIXME|BUG|NOTE):(.+)$")

type match struct {
	File string
	Line uint64
	Type string
	Text string
}

func init() {
	RootCmd.PersistentFlags().BoolVarP(&debug, "debug", "d", false, "Display debug information")
	RootCmd.Flags().StringVarP(&scannConfigPath, "config", "c", "", "Use the specified configuration file (and set it's directory as the working directory")
}

// RootCmd is the scann's root command.
var RootCmd = &cobra.Command{
	Use:   "scann",
	Short: "Summarise Code ANNotations (NOTE, TODO, FIXME, BUG) ",
	Long:  "Summarise Code ANNotations (NOTE, TODO, FIXME, BUG). See https://github.com/z0mbie42/scann",
	Run: func(cmd *cobra.Command, args []string) {
		var err error

		if debug {
			log.Config(astroflow.SetLevel(astroflow.DebugLevel))
		}

		// change working directory as the file's
		if scannConfigPath != "" {
			dir := filepath.Dir(scannConfigPath)
			err = os.Chdir(dir)
			if err != nil {
				log.Fatal(err.Error())
			}
			scannConfigPath = filepath.Base(scannConfigPath)
		}

		conf, err := config.Get(scannConfigPath)
		if err != nil {
			log.Fatal(err.Error())
		}

		log.With("configuration", conf).Debug("")

		walker, err := fswalk.NewWalker(
			fswalk.IgnoreGlob(conf.Ignore),
		)
		if err != nil {
			log.Fatal(err.Error())
		}
		filesc, _ := walker.Walk(".")
		var wg sync.WaitGroup
		for file := range filesc {
			if file.Path == "." || file.IsDir || file.IsSymLink {
				continue
			}
			wg.Add(1)
			go func(filePath string) {
				err := processFile(filePath)
				if err != nil {
					log.With("file", filePath).Error(err.Error())
				}
				wg.Done()
			}(file.Path)
		}
		wg.Wait()
	},
}

func processFile(filePath string) error {
	log.With("file", filePath).Debug("scanning file for annotations")
	file, err := os.Open(filePath)
	if err != nil {
		return err
	}
	defer file.Close()

	matchs := []match{}

	scanner := bufio.NewScanner(file)
	var i uint64
	for scanner.Scan() {
		line := scanner.Text()
		lineMatchs := reg.FindAllStringSubmatch(line, -1)
		for _, m := range lineMatchs {
			found := match{
				File: filePath,
				Line: i,
				Type: m[1],
				Text: strings.TrimSpace(m[2]),
			}
			matchs = append(matchs, found)
		}

		i += 1
	}

	if err := scanner.Err(); err != nil {
		return err
	}

	for _, m := range matchs {
		fmt.Printf("%s:%d: %s: %s\n", m.File, m.Line, m.Type, m.Text)
	}
	return nil
}
