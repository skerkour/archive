package commands

import (
	"fmt"
	"os"
	"path/filepath"

	"github.com/bloom42/rocket/config"
	"github.com/bloom42/rocket/providers/awseb"
	"github.com/bloom42/rocket/providers/awss3"
	"github.com/bloom42/rocket/providers/docker"
	"github.com/bloom42/rocket/providers/ghreleases"
	"github.com/bloom42/rocket/providers/heroku"
	"github.com/bloom42/rocket/providers/script"
	"github.com/bloom42/rocket/providers/zeitnow"
	"github.com/bloom42/rz-go"
	"github.com/bloom42/rz-go/log"
	"github.com/spf13/cobra"
)

var rocketConfigPath string
var debug bool

func init() {
	RocketCmd.PersistentFlags().BoolVarP(&debug, "debug", "d", false, "Display debug information")
	RocketCmd.Flags().StringVarP(&rocketConfigPath, "config", "c", "", "Use the specified configuration file (and set it's directory as the working directory")
}

// RocketCmd is the rocket's root command. It's used to actually deploy
var RocketCmd = &cobra.Command{
	Use:   "rocket",
	Short: "Automated software delivery as fast and easy as possible",
	Long:  "Automated software delivery as fast and easy as possible. rocket is the D in CI/CD. See https://github.com/bloom42/rocket",
	Run: func(cmd *cobra.Command, args []string) {
		var err error

		if debug {
			log.Logger = log.Config(rz.Level(rz.DebugLevel))
		}

		// change working directory as the file's
		if rocketConfigPath != "" {
			dir := filepath.Dir(rocketConfigPath)
			err = os.Chdir(dir)
			if err != nil {
				log.Fatal(err.Error(), nil)
			}
			rocketConfigPath = filepath.Base(rocketConfigPath)
		}

		conf, err := config.Get(rocketConfigPath)
		if err != nil {
			log.Fatal(err.Error(), nil)
		}

		log.Debug("", func(e *rz.Event) {
			e.Interface("configuration", conf).
			Strings("env", os.Environ())
		})

		// script
		if conf.Script != nil {
			log.Debug("script: starting provider", nil)
			err = script.Deploy(conf.Script)
			if err != nil {
				log.Fatal(fmt.Sprintf("script: %v", err), nil)
			}
		} else {
			log.Debug("script: provider is empty", nil)
		}

		// heroku
		if conf.Heroku != nil {
			log.Debug("heroku: starting provider", nil)
			err = heroku.Deploy(*conf.Heroku)
			if err != nil {
				log.Fatal(fmt.Sprintf("heroku: %v", err), nil)
			}
		} else {
			log.Debug("heroku: provider is empty", nil)
		}

		// github_releases
		if conf.GitHubReleases != nil {
			log.Debug("github_releases: starting provider", nil)
			err = ghreleases.Deploy(*conf.GitHubReleases)
			if err != nil {
				log.Fatal(fmt.Sprintf("github_releases: %v", err), nil)
			}
		} else {
			log.Debug("github_releases: provider is empty", nil)
		}

		// docker
		if conf.Docker != nil {
			log.Debug("docker: starting provider", nil)
			err = docker.Deploy(*conf.Docker)
			if err != nil {
				log.Fatal(fmt.Sprintf("docker: %v", err), nil)
			}
		} else {
			log.Debug("docker: provider is empty", nil)
		}

		// aws_s3
		if conf.AWSS3 != nil {
			log.Debug("aws_s3: starting provider", nil)
			err = awss3.Deploy(*conf.AWSS3)
			if err != nil {
				log.Fatal(fmt.Sprintf("aws_s3: %v", err), nil)
			}
		} else {
			log.Debug("aws_s3: provider is empty", nil)
		}

		// zeit_now
		if conf.ZeitNow != nil {
			log.Debug("zeit_now: starting provider", nil)
			err = zeitnow.Deploy(*conf.ZeitNow)
			if err != nil {
				log.Fatal(fmt.Sprintf("zeit_now: %v", err), nil)
			}
		} else {
			log.Debug("zeit_now: provider is empty", nil)
		}

		// aws_eb
		if conf.AWSEB != nil {
			log.Debug("aws_eb: starting provider", nil)
			err = awseb.Deploy(*conf.AWSEB)
			if err != nil {
				log.Fatal(fmt.Sprintf("aws_eb: %v", err), nil)
			}
		} else {
			log.Debug("aws_eb: provider is empty", nil)
		}
	},
}
