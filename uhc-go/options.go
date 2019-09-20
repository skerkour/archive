package uhc

import (
	"crypto/tls"
	"net"
	"net/http"
	"net/http/cookiejar"
	"time"
)

// Client
type ClientOption func(client *Client) error

// create a default client
func newHTTPClient() *http.Client {
	jar, _ := cookiejar.New(nil)
	transport := &http.Transport{
		Proxy: http.ProxyFromEnvironment,
		DialContext: (&net.Dialer{
			Timeout:   30 * time.Second,
			KeepAlive: 30 * time.Second,
			DualStack: true,
		}).DialContext,
		MaxIdleConns:          100,
		IdleConnTimeout:       90 * time.Second,
		TLSHandshakeTimeout:   10 * time.Second,
		ExpectContinueTimeout: 1 * time.Second,
	}
	return &http.Client{
		Jar:       jar,
		Transport: transport,
		Timeout:   2 * time.Minute,
	}
}

// HTTPClient return the default underlying http client
func (r *Client) HTTPClient() *http.Client {
	if r.httpClient == nil {
		r.httpClient = newHTTPClient()
	}
	return r.httpClient
}

func (r *Client) getTransport() *http.Transport {
	trans, _ := r.HTTPClient().Transport.(*http.Transport)
	return trans
}

// EnableInsecureTLS allows insecure https
func EnableInsecureTLS(enable bool) ClientOption {
	return func(r *Client) error {
		trans := r.getTransport()
		if trans == nil {
			return nil
		}
		if trans.TLSClientConfig == nil {
			trans.TLSClientConfig = &tls.Config{}
		}
		trans.TLSClientConfig.InsecureSkipVerify = enable
		return nil
	}
}
