package denv

import (
	"os"
)

// Env is a Key: Value map for the environement
type Env map[string]string

// Init the default environment
func Init(env Env) error {
	var err error

	for key, value := range env {
		currentValue := os.Getenv(key)
		if currentValue == "" {
			err = os.Setenv(key, value)
			if err != nil {
				return err
			}
		}
	}
	return nil
}
