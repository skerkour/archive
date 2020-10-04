package install

import (
	"errors"
	"os"
	"path/filepath"
)

func DefaultInstallDir() (string, error) {
	home, err := os.UserHomeDir()
	if err != nil {
		return "", err
	}
	return filepath.Join(home, ".local", "bin"), nil
}

func DefaultBinary() (string, error) {
	gopath := os.Getenv("GOPATH")
	if gopath == "" {
		return "", errors.New("$GOPATH not found. aborting")
	}

	return filepath.Join(gopath, "bin", "appbox"), nil
}

// Run the install command
func Run(args []string) (err error) {
	installDir, err := DefaultInstallDir()
	if err != nil {
		return
	}

	err = os.MkdirAll(installDir, 0700)
	if err != nil {
		return
	}

	target, err := DefaultBinary()
	if err != nil {
		return
	}

	apps := []string{"music", "rss", "calc"}
	for _, app := range apps {
		err = os.Symlink(target, filepath.Join(installDir, app))
		if err != nil {
			return
		}
	}
	return
}
