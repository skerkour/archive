package message

import (
	"gitlab.com/z0mbie42/ptbot/service/util"
)

type Create struct {
	SenderID int
	Text     string
	ChatID   string
}

func (cmd Create) Validate(aggregate interface{}) error {
	return nil
}

func (c Create) BuildEvent() (interface{}, error) {
	uuid, err := util.GenerateUUID()
	if err != nil {
		return nil, err
	}

	return CreatedV1{
		ID:       uuid,
		SenderID: c.SenderID,
		Text:     c.Text,
		ChatID:   c.ChatID,
	}, nil
}
