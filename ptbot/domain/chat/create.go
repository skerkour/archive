package chat

import (
	"errors"

	"gitlab.com/z0mbie42/ptbot/service/util"
)

type Create struct {
	TelegramID int64
	Title      string
	Username   string
	Type       string
}

func (cmd Create) Validate(aggregate interface{}) error {
	if cmd.TelegramID == 0 {
		return errors.New("TelegramID is not valid")
	}

	return nil
}

func (c Create) BuildEvent() (interface{}, error) {
	uuid, err := util.GenerateUUID()
	if err != nil {
		return nil, err
	}

	return CreatedV1{
		ID:         uuid,
		TelegramID: c.TelegramID,
		Title:      c.Title,
		Username:   c.Username,
		Type:       c.Type,
	}, nil
}
