package product

import (
	"errors"

	"gitlab.com/z0mbie42/ptbot/service/util"
)

type Create struct {
	ASIN        string `json:"asin"`
	URL         string `json:"url"`
	Marketplace string `json:"marketplace"`
}

func (cmd Create) Validate(aggregate interface{}) error {
	if cmd.ASIN == "" {
		return errors.New("ASIN is not valid")
	}

	if cmd.URL == "" {
		return errors.New("URL is not valid")
	}

	if cmd.Marketplace == "" {
		return errors.New("Marketplace is not valid")
	}
	return nil
}

func (c Create) BuildEvent() (interface{}, error) {
	uuid, err := util.GenerateUUID()
	if err != nil {
		return nil, err
	}

	return CreatedV1{
		ID:          uuid,
		ASIN:        c.ASIN,
		URL:         c.URL,
		Marketplace: c.Marketplace,
	}, nil
}
