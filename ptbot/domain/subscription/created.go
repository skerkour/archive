package subscription

import (
	"github.com/z0mbie42/goes"
	"gitlab.com/z0mbie42/ptbot/domain"
)

type CreatedV1 struct {
	ID           string  `json:"id"`
	Webhook      *string `json:"webhook"`
	Notification bool    `json:"notification"`
	ProductID    string  `json:"product_id"`
	ChatID       string  `json:"chat_id"`
}

func (eventData CreatedV1) Apply(aggregate goes.Aggregate, event goes.Event) {
	sub := aggregate.(*domain.Subscription)

	sub.ID = eventData.ID
	sub.CreatedAt = event.Timestamp
	sub.Webhook = eventData.Webhook
	sub.Notification = eventData.Notification
	sub.ProductID = eventData.ProductID
	sub.ChatID = eventData.ChatID
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
