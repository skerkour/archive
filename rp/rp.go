package main

import (
	"bytes"
	"fmt"
	"io/ioutil"
	"os"
	"regexp"
	"strings"
	"sync"
	"unicode/utf8"

	"github.com/bloom42/astro-go/log"
	"github.com/spf13/cobra"
	"github.com/z0mbie42/fswalk"
)

const (
	// NotSlash is any rune but path separator.
	notSlash = "[^/]"
	// AnyRune is zero or more non-path separators.
	anyRune = notSlash + "*"
	// ZeroOrMoreDirectories is used by ** patterns.
	zeroOrMoreDirectories = `(?:[.{}\w\-\ ]+\/)*`
	// TrailingStarStar matches everything inside directory.
	trailingStarStar = "/**"
	// SlashStarStarSlash maches zero or more directories.
	slashStarStarSlash = "/**/"
)

var rootMaxFilesize int64
var rootPlan bool
var rootIgnore = []string{".git/**"}

func init() {
	rootCmd.PersistentFlags().Int64VarP(&rootMaxFilesize, "max-filesize", "m", 500000000, "Ignore files larger than the given size (in bytes)")
	rootCmd.PersistentFlags().BoolVarP(&rootPlan, "plan", "p", false, "Display modifications without actually doing it")
	rootCmd.PersistentFlags().StringArrayVarP(&rootIgnore, "ignore", "i", rootIgnore, "Fiels to ignore (glob pattern)")
}

var rootCmd = &cobra.Command{
	Use:   "rp <old> <new>",
	Short: "The simplest recursive string replacer. Use it with caution",
	Long:  "The simplest recursive string replacer. Use it with caution",
	Args:  cobra.ExactArgs(2),
	Run: func(cmd *cobra.Command, args []string) {
		walker, _ := fswalk.NewWalker()
		var errcList []<-chan error
		var wg sync.WaitGroup

		ignorePatterns, err := globToRegexp(rootIgnore)
		if err != nil {
			log.Fatal(err.Error())
		}

		filesc, errc := walker.Walk(".")
		errcList = append(errcList, errc)

		errc = processFiles(filesc, []byte(args[0]), []byte(args[1]), ignorePatterns)
		errcList = append(errcList, errc)

		errc = mergeErrors(errcList...)

		wg.Add(1)
		go func() {
			for err := range errc {
				fmt.Fprintf(os.Stderr, "error: %s\n", err)
			}
			wg.Done()
		}()
		wg.Wait()
	},
}

// mergeErrors merges multiple channels of errors.
// Based on https://blog.golang.org/pipelines.
func mergeErrors(cs ...<-chan error) <-chan error {
	var wg sync.WaitGroup

	// We must ensure that the output channel has the capacity to
	// hold as many errors
	// as there are error channels.
	// This will ensure that it never blocks, even
	// if WaitForPipeline returns early.
	out := make(chan error, len(cs))

	// Start an output goroutine for each input channel in cs.  output
	// copies values from c to out until c is closed, then calls
	// wg.Done.
	output := func(c <-chan error) {
		for n := range c {
			out <- n
		}
		wg.Done()
	}
	wg.Add(len(cs))
	for _, c := range cs {
		go output(c)
	}

	// Start a goroutine to close out once all the output goroutines
	// are done.  This must start after the wg.Add call.
	go func() {
		wg.Wait()
		close(out)
	}()
	return out
}

// matchAny returns true if the the given path match any of the given patterns
func matchAny(path string, patterns []*regexp.Regexp) bool {
	for _, pattern := range patterns {
		if pattern.MatchString(path) {
			return true
		}
	}
	return false
}

// globToRegexp transform an array of glob patterns to an array of golang regexp, and returns at
// the first encountered error
func globToRegexp(patterns []string) ([]*regexp.Regexp, error) {
	ret := make([]*regexp.Regexp, len(patterns))

	for i, pattern := range patterns {
		reg, err := Globexp(pattern)
		if err != nil {
			return ret, err
		}
		ret[i] = reg
	}
	return ret, nil
}

// Globexp builds a regular express from from extended glob pattern and then
// returns a Regexp object.
func Globexp(glob string) (*regexp.Regexp, error) {
	var re bytes.Buffer

	re.WriteString("^")

	i, inGroup, L := 0, false, len(glob)

	for i < L {
		r, w := utf8.DecodeRuneInString(glob[i:])

		switch r {
		default:
			re.WriteRune(r)

		case '\\', '$', '^', '+', '.', '(', ')', '=', '!', '|':
			re.WriteRune('\\')
			re.WriteRune(r)

		case '/':
			// TODO optimize later, string could be long
			rest := glob[i:]
			re.WriteRune('/')
			if strings.HasPrefix(rest, "/**/") {
				re.WriteString(zeroOrMoreDirectories)
				w *= 4
			} else if rest == "/**" {
				re.WriteString(".*")
				w *= 3
			}

		case '?':
			re.WriteRune('.')

		case '[', ']':
			re.WriteRune(r)

		case '{':
			if i < L-1 {
				if glob[i+1:i+2] == "{" {
					re.WriteString("\\{")
					w *= 2
					break
				}
			}
			inGroup = true
			re.WriteRune('(')

		case '}':
			if inGroup {
				inGroup = false
				re.WriteRune(')')
			} else {
				re.WriteRune('}')
			}

		case ',':
			if inGroup {
				re.WriteRune('|')
			} else {
				re.WriteRune('\\')
				re.WriteRune(r)
			}

		case '*':
			rest := glob[i:]
			if strings.HasPrefix(rest, "**/") {
				re.WriteString(zeroOrMoreDirectories)
				w *= 3
			} else {
				re.WriteString(anyRune)
			}
		}

		i += w
	}

	re.WriteString("$")
	return regexp.Compile(re.String())
}

func processFiles(filesc <-chan fswalk.File, old, new []byte, ignorePatterns []*regexp.Regexp) <-chan error {
	ret := make(chan error)

	go func() {
		for file := range filesc {
			if file.IsDir ||
				file.Size > rootMaxFilesize ||
				matchAny(file.Path, ignorePatterns) {
				continue
			}

			buf, err := ioutil.ReadFile(file.Path)
			if err != nil {
				ret <- err
				continue
			}

			if bytes.Contains(buf, old) {
				fmt.Println(file.Path)
				if rootPlan {
					continue
				}
				output := bytes.Replace(buf, old, new, -1)
				err = ioutil.WriteFile(file.Path, output, file.Mode)
				if err != nil {
					ret <- err
					continue
				}
			}

		}
		close(ret)
	}()

	return ret
}
