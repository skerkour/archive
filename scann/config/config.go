package config

import (
	"os"

	"github.com/phasersec/san-go"
)

const DefaultConfigurationFileName = ".scann.san"

type Config struct {
	Ignore []string `san:"ignore"`
	Format *string  `san:"format"`
}

// FindConfigFile return the path of the first configuration file found
// it returns an emtpy string if none is found
func FindConfigFile(file string) string {
	if file != "" {
		if fileExists(file) {
			return file
		}
		return ""
	}

	if fileExists(DefaultConfigurationFileName) {
		return DefaultConfigurationFileName
	}

	return ""
}

func Default() Config {
	var conf Config
	return fillDefault(conf)
}

// Get return the parsed found configuration file or an error
func Get(file string) (Config, error) {
	var err error
	var config Config

	configFilePath := FindConfigFile(file)

	if configFilePath == "" {
		return Default(), nil
	}

	config, err = parseConfig(configFilePath)
	if err != nil {
		return config, err
	}

	config = fillDefault(config)

	return config, err
}

func fileExists(path string) bool {
	if _, err := os.Stat(path); err == nil {
		return true
	}
	return false
}

func parseConfig(configFilePath string) (Config, error) {
	var ret Config
	var err error

	err = san.Load(configFilePath, &ret)
	return ret, err
}

func fillDefault(conf Config) Config {
	if conf.Ignore == nil {
		conf.Ignore = []string{".git/**"}
	}

	if conf.Format == nil || *conf.Format == "" {
		v := "console"
		conf.Format = &v
	}
	return conf
}
