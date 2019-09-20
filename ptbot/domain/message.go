package domain

import (
	"github.com/z0mbie42/goes"
)

type Message struct {
	goes.BaseAggregate
	SenderID int
	Text     string

	ChatID string
}
