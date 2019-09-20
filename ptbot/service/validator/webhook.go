package validator

import (
	"errors"
	"net/url"
)

func WebhookURL(productURL string) error {
	u, err := url.Parse(productURL)
	if err != nil {
		return err
	}

	if u.Scheme != "https" {
		return errors.New("https is required")
	}

	if u.Host == "" {
		return errors.New("Host is not valid")
	}
	return nil
}
