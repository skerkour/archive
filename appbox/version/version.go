package version

import (
	"runtime"
)

// set at build time
var GitCommit string
var UTCBuildTime string
var GoVersion string

const (
	OS      = runtime.GOOS
	Arch    = runtime.GOARCH
	Name    = "appbox"
	Version = "0.1.0"
)
