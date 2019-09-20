package script

import (
	"fmt"
	"io"
	"os"
	"os/exec"

	"github.com/bloom42/rocket/config"
	"github.com/bloom42/rz-go/log"
)

// Deploy deploy the script part of the configuration
// It sequentially execute all the given scripts
func Deploy(conf config.ScriptConfig) error {
	for _, script := range conf {
		var err error

		script = config.ExpandEnv(script)
		cmd := exec.Command("sh", "-c", script)

		stdout, err := cmd.StdoutPipe()
		if err != nil {
			return err
		}
		stderr, err := cmd.StderrPipe()
		if err != nil {
			return err
		}

		go func() {
			io.Copy(os.Stdout, stdout)
		}()
		go func() {
			io.Copy(os.Stderr, stderr)
		}()

		err = cmd.Start()
		if err != nil {
			return err
		}
		err = cmd.Wait()
		if err != nil {
			return err
		}
		log.Info(fmt.Sprintf("script: %s successfully executed", script), nil)
	}

	log.Info("script: successfully proceeded", nil)
	return nil
}
