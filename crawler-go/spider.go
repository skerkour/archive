package crawler

type Spider interface {
	GetStartRequests() []Request
	GetConcurrency() uint32
	Run(Request) ([]Request, error)
	Init()
}
