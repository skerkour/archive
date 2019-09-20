package message

import (
	"github.com/z0mbie42/goes"
	"gitlab.com/z0mbie42/ptbot/domain"
)

type CreatedV1 struct {
	ID       string `json:"id"`
	SenderID int    `json:"sender_id"`
	Text     string `json:"text"`
	ChatID   string `json:"chat_id"`
}

func (eventData CreatedV1) Apply(aggregate goes.Aggregate, event goes.Event) {
	message := aggregate.(*domain.Message)

	message.ID = eventData.ID
	message.CreatedAt = event.Timestamp
	message.Text = eventData.Text
	message.SenderID = eventData.SenderID
	message.ChatID = eventData.ChatID
}

func (CreatedV1) AggregateType() string {
	return "message"
}

func (CreatedV1) Action() string {
	return "created"
}

func (CreatedV1) Version() uint64 {
	return 1
}
