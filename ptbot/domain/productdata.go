package domain

import (
	"github.com/z0mbie42/goes"
)

type ProductData struct {
	goes.BaseAggregate
	Title    string  `json:"title"`
	Price    float64 `json:"price"`
	Currency string  `json:"currency"`

	ProductID string
}

func (ProductData) TableName() string {
	return "products_data"
}
