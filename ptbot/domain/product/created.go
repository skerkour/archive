package product

import (
	"github.com/z0mbie42/goes"
	"gitlab.com/z0mbie42/ptbot/domain"
)

type CreatedV1 struct {
	ID          string `json:"id"`
	ASIN        string `json:"asin"`
	URL         string `json:"url"`
	Marketplace string `json:"marketplace"`
}

func (eventData CreatedV1) Apply(aggregate goes.Aggregate, event goes.Event) {
	product := aggregate.(*domain.Product)

	product.ID = eventData.ID
	product.CreatedAt = event.Timestamp
	product.ASIN = eventData.ASIN
	product.URL = eventData.URL
	product.Marketplace = eventData.Marketplace
}

func (CreatedV1) AggregateType() string {
	return "product"
}

func (CreatedV1) Action() string {
	return "created"
}

func (CreatedV1) Version() uint64 {
	return 1
}
