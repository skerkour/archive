package crawler

type Response interface {
	Parse() ([]Item, []Request, error)
}
