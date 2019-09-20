package main

import (
	"fmt"
	"log"
	"os"
	"strings"

	"github.com/jmoiron/sqlx"
	_ "github.com/lib/pq"
)

func main() {
	if len(os.Args) != 1 {
		Enumerate(os.Args[1])
	} else {
		usage()
	}
}

func usage() {
	fmt.Println("crtsh [query]\vexample: crtsh '%.kerkour.com'")
	os.Exit(1)
}

func reverseStr(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < len(r)/2; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

type CrtshDomain struct {
	Domain string `db:"domain"`
}

// Enumerate try to find all the subdomains associated with the given domain
// it assumes that `domain` is clean (no whitespaces...)
func Enumerate(domain string) {
	var err error
	uniqDomains := map[string]bool{}

	crtshdb, err := sqlx.Connect("postgres", "host=crt.sh user=guest dbname=certwatch sslmode=disable")
	if err != nil {
		log.Fatal(err)
	}

	subdomainsPattern := domain

	crtshDomains := []CrtshDomain{}
	idx := strings.Index(subdomainsPattern, "%")
	idxrev := strings.Index(reverseStr(subdomainsPattern), "%")
	if idx != -1 && idx < idxrev {
		err = crtshdb.Select(&crtshDomains, `SELECT DISTINCT ci.NAME_VALUE as domain
			FROM certificate_identity ci
			WHERE reverse(lower(ci.NAME_VALUE)) LIKE reverse(lower($1))`, subdomainsPattern)
	} else {
		err = crtshdb.Select(&crtshDomains, `SELECT DISTINCT ci.NAME_VALUE as domain
			FROM certificate_identity ci
			WHERE lower(ci.NAME_VALUE) LIKE lower($1)`, subdomainsPattern)
	}
	if err != nil {
		log.Fatal(err)
	}

	for _, crtshDomain := range crtshDomains {
		domain := strings.ToLower(strings.TrimSpace(crtshDomain.Domain))
		uniqDomains[domain] = true
	}

	for domain := range uniqDomains {
		fmt.Println(domain)
	}
}

