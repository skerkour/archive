package rule

import (
	"regexp"
	"strings"

	"github.com/bloom42/flint/lint"
)

var partialSnakeCaseRegex = regexp.MustCompile("^[a-z0-9_A-Z]*$")

type SnakeCase struct{}

func (r SnakeCase) Apply(file lint.File) []lint.Issue {
	parts := strings.Split(strings.TrimSuffix(file.Name, file.Ext), ".")
	issues := []lint.Issue{}

	for _, part := range parts {
		if part != strings.ToLower(part) {
			issue := lint.Issue{
				Rule:    r.Name(),
				Message: "alphanumeric characters should be lower cased",
			}
			issues = append(issues, issue)
		}

		if strings.Index(part, "__") != -1 {
			issue := lint.Issue{
				Rule:    r.Name(),
				Message: "cannot have multiple consecutive underscores",
			}
			issues = append(issues, issue)
		}

		if partialSnakeCaseRegex.MatchString(part) != true {
			issue := lint.Issue{
				Rule:    r.Name(),
				Message: "snake case should only contains alphanumeric characters and underscores",
			}
			issues = append(issues, issue)
		}
	}

	return issues
}

func (_ SnakeCase) Name() string {
	return "snake_case"
}
