package fswalk

import (
	"os"

	"github.com/gobwas/glob"
)

// FollowLinks configure the walker to follow links or not
func FollowLinks(shouldFollow bool) WalkerOption {
	return func(walker *Walker) error {
		walker.followLinks = shouldFollow
		return nil
	}
}

func IgnoreGlob(strPatterns []string) WalkerOption {
	return func(walker *Walker) error {
		patterns := []glob.Glob{}
		for _, pattern := range strPatterns {
			p, err := glob.Compile(pattern, os.PathSeparator)
			if err != nil {
				return nil
			}
			patterns = append(patterns, p)
		}
		walker.globPatterns = patterns
		return nil
	}

}
