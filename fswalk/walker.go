package fswalk

import (
	"github.com/gobwas/glob"
	"io/ioutil"
	"os"
	"path/filepath"
)

type Walker struct {
	followLinks  bool
	globPatterns []glob.Glob
}

type WalkerOption func(walker *Walker) error

func NewWalker(options ...WalkerOption) (Walker, error) {
	ret := Walker{followLinks: true, globPatterns: []glob.Glob{}}
	var err error

	for _, option := range options {
		err = option(&ret)
		if err != nil {
			return ret, err
		}
	}

	return ret, nil
}

func (walker *Walker) Config(options ...WalkerOption) error {
	var err error

	for _, option := range options {
		err = option(walker)
		if err != nil {
			return err
		}
	}

	return nil
}

// Walk recursively traverse the given path
func (walker *Walker) Walk(root string) (<-chan File, <-chan error) {
	outc := make(chan File)
	errc := make(chan error)

	go func() {
		walker.walk(root, outc, errc)
		close(outc)
		close(errc)
	}()

	return outc, errc
}

func (walker *Walker) walk(path string, filec chan<- File, errc chan<- error) {
	info, err := os.Lstat(path)
	if err != nil {
		errc <- err
		return
	}

	file := File{
		Path:      path,
		Name:      info.Name(),
		Size:      info.Size(),
		Mode:      info.Mode(),
		IsSymLink: (info.Mode()&os.ModeSymlink != 0),
		IsDir:     info.IsDir(),
		ModTime:   info.ModTime(),
	}

	ignore := false
	for _, globPattern := range walker.globPatterns {
		if globPattern.Match(path) {
			ignore = true
			break
		}
	}

	if ignore == false {
		filec <- file
	}

	if file.IsDir {
		if file.IsSymLink && walker.followLinks != true {
			return
		}
		files, err := ioutil.ReadDir(path)
		if err != nil {
			errc <- err
			return
		}

		for _, file := range files {
			walker.walk(filepath.Join(path, file.Name()), filec, errc)
		}
	}
}
