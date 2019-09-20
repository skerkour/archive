package crawler

type Request interface {
	// unique id for request to verify if it has been processed eg. url
	ID() string
	Fetch() (Response, error)
}
