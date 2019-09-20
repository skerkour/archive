package domain

import (
	"github.com/z0mbie42/goes"
)

type Product struct {
	goes.BaseAggregate
	ASIN        string `json:"asin"`
	URL         string `json:"url"`
	Marketplace string `json:"marketplace"`

	History []ProductData
}
