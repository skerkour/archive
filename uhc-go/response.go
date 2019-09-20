package uhc

import (
	"net/http"
	"time"
)

// Response represents a request with it's response
type Response struct {
	client       *Client
	httpRequest  *http.Request
	httpResponse *http.Response
	httpClient   *http.Client
	duration     time.Duration
}

// Duration return the request's duration
func (resp *Response) Duration() time.Duration {
	return resp.duration
}

// TODO
func (resp *Response) Dump() string {
	return ""
}

// TODO
func (resp *Response) Response() *http.Response {
	return nil
}

// TODO
// Bytes returns response body as []byte
func (resp *Response) Bytes() ([]byte, error) {
	return nil, nil
}

// TODO
// String returns response body as string
func (resp *Response) String() (string, error) {
	return "", nil
}

// TODO
// JSON converts json response body to struct or map
func (resp *Response) JSON(v interface{}) error {
	return nil
}

// TODO
// XML convert xml response body to struct or map
func (resp *Response) XML(v interface{}) error {
	return nil
}
