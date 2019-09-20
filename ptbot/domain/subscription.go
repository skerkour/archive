package domain

import (
	"github.com/z0mbie42/goes"
)

type Subscription struct {
	goes.BaseAggregate
	Webhook      *string
	Notification bool `json:"notification"`

	ProductID string
	ChatID    string
}
