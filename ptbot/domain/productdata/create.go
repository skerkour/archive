package productdata

import (
	"errors"

	"gitlab.com/z0mbie42/ptbot/service/util"
)

type Create struct {
	Title     string  `json:"title"`
	Price     float64 `json:"price"`
	Currency  string  `json:"currency"`
	ProductID string
}

func (cmd Create) Validate(aggregate interface{}) error {
	if cmd.Price == 0.0 {
		return errors.New("Price is not valid")
	}

	if cmd.Currency != "EUR" {
		return errors.New("Currency is not valid")
	}

	if cmd.ProductID == "" {
		return errors.New("ProductID is not valid")
	}
	return nil
}

func (c Create) BuildEvent() (interface{}, error) {
	uuid, err := util.GenerateUUID()
	if err != nil {
		return nil, err
	}

	return CreatedV1{
		ID:        uuid,
		Title:     c.Title,
		Price:     c.Price,
		Currency:  c.Currency,
		ProductID: c.ProductID,
	}, nil
}
