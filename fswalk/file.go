package fswalk

import (
	"os"
	"time"
)

type File struct {
	Path      string
	Name      string
	Size      int64
	IsSymLink bool
	IsDir     bool
	Mode      os.FileMode
	ModTime   time.Time
}
