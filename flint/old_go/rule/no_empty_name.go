package rule

import (
	"strings"

	"github.com/bloom42/flint/lint"
)

type NoEmptyName struct{}

func (r NoEmptyName) Apply(file lint.File) []lint.Issue {
	issues := []lint.Issue{}

	if strings.TrimSpace(file.Name) == "" {
		issue := lint.Issue{
			Rule:    r.Name(),
			Message: "Name should not be compsed exclusively of whitespaces",
		}
		issues = append(issues, issue)

	}
	return issues
}

func (_ NoEmptyName) Name() string {
	return "no_empty_name"
}
