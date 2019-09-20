package chat

import (
	"github.com/z0mbie42/goes"
	"gitlab.com/z0mbie42/ptbot/domain"
)

type CreatedV1 struct {
	ID         string `json:"id"`
	TelegramID int64  `json:"telegram_id"`
	Title      string `json:"title"`
	Username   string `json:"username"`
	Type       string `json:"type"`
}

func (eventData CreatedV1) Apply(aggregate goes.Aggregate, event goes.Event) {
	chat := aggregate.(*domain.Chat)

	chat.ID = eventData.ID
	chat.CreatedAt = event.Timestamp
	chat.TelegramID = eventData.TelegramID
	chat.Title = eventData.Title
	chat.Username = eventData.Username
	chat.Type = eventData.Type
}

func (CreatedV1) AggregateType() string {
	return "chat"
}

func (CreatedV1) Action() string {
	return "created"
}

func (CreatedV1) Version() uint64 {
	return 1
}
