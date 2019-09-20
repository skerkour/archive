package subscription

import (
	"errors"

	"github.com/z0mbie42/goes"
	"gitlab.com/z0mbie42/ptbot/domain"
	"gitlab.com/z0mbie42/ptbot/service/util"
	"gitlab.com/z0mbie42/ptbot/service/validator"
)

type Create struct {
	Webhook      *string `json:"webhook"`
	Notification bool    `json:"notification"`
	ProductID    string  `json:"product_id"`
	ChatID       string  `json:"chat_id"`
}

func (cmd Create) Validate(aggregate interface{}) error {
	var err error
	existingSub := &domain.Subscription{}

	if cmd.Webhook != nil {
		if err = validator.WebhookURL(*cmd.Webhook); err != nil {
			return nil
		}
	}

	err = goes.DB.Where("chat_id = ? AND product_id = ?", cmd.ChatID, cmd.ProductID).First(existingSub).Error
	if err != nil && goes.IsRecordNotFoundError(err) == false {
		return err
	} else if existingSub.ID != "" {
		return errors.New("Subscription already exists")
	}
	return nil
}

func (c Create) BuildEvent() (interface{}, error) {
	uuid, err := util.GenerateUUID()
	if err != nil {
		return nil, err
	}

	return CreatedV1{
		ID:           uuid,
		Webhook:      c.Webhook,
		Notification: c.Notification,
		ProductID:    c.ProductID,
		ChatID:       c.ChatID,
	}, nil
}
