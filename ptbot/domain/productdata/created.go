package productdata

import (
	"github.com/z0mbie42/goes"
	"gitlab.com/z0mbie42/ptbot/domain"
)

type CreatedV1 struct {
	ID        string  `json:"id"`
	Title     string  `json:"title"`
	Price     float64 `json:"price"`
	Currency  string  `json:"currency"`
	ProductID string  `json:"product_id"`
}

func (eventData CreatedV1) Apply(aggregate goes.Aggregate, event goes.Event) {
	productdata := aggregate.(*domain.ProductData)

	productdata.ID = eventData.ID
	productdata.CreatedAt = event.Timestamp
	productdata.Title = eventData.Title
	productdata.Price = eventData.Price
	productdata.Currency = eventData.Currency
	productdata.ProductID = eventData.ProductID
}

func (CreatedV1) AggregateType() string {
	return "productdata"
}

func (CreatedV1) Action() string {
	return "created"
}

func (CreatedV1) Version() uint64 {
	return 1
}
