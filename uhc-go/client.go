package uhc

import (
	"errors"
	"net/http"
)

// default *Client
var defaultClient = New()

// Client is a convenient client to perform requests
type Client struct {
	httpClient *http.Client
}

// New create a new *Client
func New() *Client {
	return &Client{}
}

// Do execute a http request with sepecify method and url,
// and it can also have some optional params, depending on your needs.
func (client *Client) Do(method, rawurl string, options ...ClientOption) (resp *Response, err error) {
	if rawurl == "" {
		return nil, errors.New("req: url not specified")
	}
	return nil, errors.New("TODO")
}

// Config apply all the options to the client
func (client *Client) Config(options ...ClientOption) error {
	var err error

	for _, option := range options {
		err = option(client)
		if err != nil {
			return err
		}
	}

	return nil
}

// Get execute a http GET request
func (client *Client) Get(url string, options ...ClientOption) (*Response, error) {
	return client.Do("GET", url, options...)
}

// Post execute a http POST request
func (client *Client) Post(url string, options ...ClientOption) (*Response, error) {
	return client.Do("POST", url, options...)
}

// Put execute a http PUT request
func (client *Client) Put(url string, options ...ClientOption) (*Response, error) {
	return client.Do("PUT", url, options...)
}

// Patch execute a http PATCH request
func (client *Client) Patch(url string, options ...ClientOption) (*Response, error) {
	return client.Do("PATCH", url, options...)
}

// Delete execute a http DELETE request
func (client *Client) Delete(url string, options ...ClientOption) (*Response, error) {
	return client.Do("DELETE", url, options...)
}

// Head execute a http HEAD request
func (client *Client) Head(url string, options ...ClientOption) (*Response, error) {
	return client.Do("HEAD", url, options...)
}

// Options execute a http OPTIONS request
func (client *Client) Options(url string, options ...ClientOption) (*Response, error) {
	return client.Do("OPTIONS", url, options...)
}

// Config apply all the options to the default client
func Config(options ...ClientOption) error {
	return defaultClient.Config(options...)
}

// Get execute a http GET request
func Get(url string, options ...ClientOption) (*Response, error) {
	return defaultClient.Get(url, options...)
}

// Post execute a http POST request
func Post(url string, options ...ClientOption) (*Response, error) {
	return defaultClient.Post(url, options...)
}

// Put execute a http PUT request
func Put(url string, options ...ClientOption) (*Response, error) {
	return defaultClient.Put(url, options...)
}

// Head execute a http HEAD request
func Head(url string, options ...ClientOption) (*Response, error) {
	return defaultClient.Head(url, options...)
}

// Options execute a http OPTIONS request
func Options(url string, options ...ClientOption) (*Response, error) {
	return defaultClient.Options(url, options...)
}

// Delete execute a http DELETE request
func Delete(url string, options ...ClientOption) (*Response, error) {
	return defaultClient.Delete(url, options...)
}

// Patch execute a http PATCH request
func Patch(url string, options ...ClientOption) (*Response, error) {
	return defaultClient.Patch(url, options...)
}

// Do execute request
func Do(method, url string, options ...ClientOption) (*Response, error) {
	return defaultClient.Do(method, url, options...)
}
