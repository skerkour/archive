package domain

import (
	"github.com/z0mbie42/goes"
)

type Chat struct {
	goes.BaseAggregate
	TelegramID int64
	Title      string
	Username   string
	Type       string
}
