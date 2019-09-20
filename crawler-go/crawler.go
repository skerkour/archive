package crawler

import (
	"container/list"
	"log"
	"sync"
)

// Special type that mimics the behavior of a channel but does not block when
// items are sent. Items are stored internally until received. Closing the Send
// channel will cause the Recv channel to be closed after all items have been
// received.
type NonBlockingChan struct {
	mutex sync.Mutex
	Send  chan<- Request
	Recv  <-chan Request
	items *list.List
}

// Loop for buffering items between the Send and Recv channels until the Send
// channel is closed.
func (n *NonBlockingChan) run(send <-chan Request, recv chan<- Request) {
	for {
		if send == nil && n.items.Len() == 0 {
			close(recv)
			break
		}
		var (
			recvChan chan<- Request
			recvVal  Request
		)
		if n.items.Len() > 0 {
			recvChan = recv
			recvVal = n.items.Front().Value.(Request)
		}
		select {
		case i, ok := <-send:
			if ok {
				n.mutex.Lock()
				n.items.PushFront(i)
				n.mutex.Unlock()
			} else {
				send = nil
			}
		case recvChan <- recvVal:
			n.mutex.Lock()
			n.items.Remove(n.items.Front())
			n.mutex.Unlock()
		}
	}
}

// Create a new non-blocking channel.
func NewNBC() *NonBlockingChan {
	var (
		send = make(chan Request)
		recv = make(chan Request)
		n    = &NonBlockingChan{
			Send:  send,
			Recv:  recv,
			items: list.New(),
		}
	)
	go n.run(send, recv)
	return n
}

// Retrieve the number of items waiting to be received.
func (n *NonBlockingChan) Len() int {
	n.mutex.Lock()
	defer n.mutex.Unlock()
	return n.items.Len()
}

type Crawler struct {
	spiders []Spider
	// the waitgroup to wait all spiders
	wg sync.WaitGroup
}

func New() *Crawler {
	return &Crawler{
		spiders: []Spider{},
	}
}

func (crawler *Crawler) AddSpiders(spiders ...Spider) *Crawler {
	crawler.spiders = append(crawler.spiders, spiders...)
	return crawler
}

func runSpider(spider Spider, request Request, nbc *NonBlockingChan, spiderWg *sync.WaitGroup) {
	defer spiderWg.Done()

	requests, err := spider.Run(request)
	if err != nil {
		log.Printf("Error: %s\n", err.Error())
	}

	for _, request := range requests {
		// enqueue all new request to crawl
		// log.Printf("Enqueueing Request: %#v\n", request)
		spiderWg.Add(1)
		nbc.Send <- request
	}
}

func (crawler *Crawler) Start() {

	for _, spider := range crawler.spiders {
		crawler.wg.Add(1)

		go func(crawlerWg *sync.WaitGroup, spider Spider) {
			spider.Init()

			startRequests := spider.GetStartRequests()
			// fmt.Println(startRequests)
			nbc := NewNBC()
			var spiderWg sync.WaitGroup

			spiderWg.Add(len(startRequests))
			// enqueue all startRequests
			for _, request := range startRequests {
				nbc.Send <- request
			}

			var i uint32
			for i = 0; i < spider.GetConcurrency(); i += 1 {
				go func(spider Spider, nbc *NonBlockingChan, spiderWg *sync.WaitGroup) {
					for request := range nbc.Recv {
						runSpider(spider, request, nbc, spiderWg)
					}
				}(spider, nbc, &spiderWg)

			}

			spiderWg.Wait()
			close(nbc.Send)
			// spider terminated
			crawlerWg.Done()

		}(&crawler.wg, spider)
	}

	crawler.wg.Wait()
}
