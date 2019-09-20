package bot

import (
	"errors"
	"fmt"
	"log"
	"net"
	"net/http"
	"regexp"
	"strconv"
	"strings"
	"time"

	"github.com/PuerkitoBio/goquery"
	"github.com/imroc/req"
	tb "github.com/tucnak/telebot"
	"github.com/z0mbie42/goes"
	"gitlab.com/z0mbie42/ptbot/domain"
	"gitlab.com/z0mbie42/ptbot/domain/productdata"
	"gitlab.com/z0mbie42/ptbot/service/util"
)

type Product struct {
	ASIN        string `json:"asin"`
	URL         string `json:"url"`
	Marketplace string `json:"marketplace"`
}

type ProductData struct {
	Title    string  `json:"title"`
	Price    float64 `json:"price"`
	Currency string  `json:"currency"`
	//OriginalPrice *float64 `json:"original_price"`
	// sotck / availability
	// nreviews
	// rating
	// prime ?
	// isAmazonChoice
	//primaryImageURL
	// imageURLs
}

func ExtractProduct(url string) (Product, error) {
	ret := Product{}
	var matches []string

	reVariant1 := regexp.MustCompile("http[s]?:\\/\\/www\\.(amazon\\..{2,6})\\/gp\\/product\\/([a-zA-Z0-9]{10})")
	matchesVariant1 := reVariant1.FindStringSubmatch(url)

	reVariant2 := regexp.MustCompile("http[s]?:\\/\\/www\\.(amazon\\..{2,6})\\/[^\\/]*\\/dp\\/([a-zA-Z0-9]{10})")
	matchesVariant2 := reVariant2.FindStringSubmatch(url)

	if (matchesVariant1 == nil || len(matchesVariant1) != 3) &&
		(matchesVariant2 == nil || len(matchesVariant2) != 3) {
		return ret, errors.New("URL is not valid")
	}

	if matchesVariant1 != nil {
		matches = matchesVariant1
	} else {
		matches = matchesVariant2
	}

	ret.ASIN = matches[2]
	ret.Marketplace = matches[1]
	ret.URL = fmt.Sprintf("https://www.%s/gp/product/%s", ret.Marketplace, ret.ASIN)

	return ret, nil
}

func extractPrice(doc *goquery.Document) string {
	variants := []string{
		"span#priceblock_ourprice",
		"span.a-size-medium.a-color-price.offer-price.a-text-normal",
	}

	for _, variation := range variants {
		if doc.Find(variation).Length() == 1 {
			return strings.TrimSpace(doc.Find(variation).Text())
		}
	}
	return ""
}

func FetchProductData(product Product) (ProductData, error) {
	ret := ProductData{}

	res, err := request(product.URL)
	if err != nil {
		return ret, err
	}

	doc, err := goquery.NewDocumentFromResponse(res)
	if err != nil {
		return ret, err
	}

	ret.Title = strings.TrimSpace(doc.Find("#productTitle").Text())

	priceStr := extractPrice(doc)
	parts := strings.Split(priceStr, " ")
	if len(parts) != 2 || parts[0] != "EUR" {
		return ret, errors.New("For the moment only european marketplaces are supported")
	}
	ret.Price, err = strconv.ParseFloat(strings.Replace(parts[1], ",", ".", -1), 64)
	if err != nil {
		return ret, err
	}

	ret.Currency = "EUR"

	return ret, nil
}

func request(url string) (*http.Response, error) {
	var netTransport = &http.Transport{
		Dial: (&net.Dialer{
			Timeout: 5 * time.Second,
		}).Dial,
		TLSHandshakeTimeout: 5 * time.Second,
	}
	var netClient = &http.Client{
		Timeout:   time.Second * 10,
		Transport: netTransport,
	}

	header := req.Header{
		"Accept":          "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8",
		"Accept-Encoding": "gzip, deflate, br",
		"Accept-Language": "en-US,en;q=0.9,fr-FR;q=0.8,fr;q=0.7,ru-RU;q=0.6,ru;q=0.5",
		"Cache-Control":   "max-age=0",
		"DNT":             "1",
		"User-Agent":      "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/60.0.3112.90 Safari/537.36",
	}

	//req.SetTimeout(8 * time.Second)

	r, err := req.Get(url, header, netClient)
	if err != nil {
		return nil, err
	}

	return r.Response(), nil
}

func Scraper() {
	// delay start to leave enought tie for the bot to launch
	time.Sleep(21 * time.Second)
	for {
		log.Printf("scraping round started")
		products := []domain.Product{}
		var err error

		// find all products
		err = goes.DB.Find(&products).Error
		if err != nil {
			log.Printf("Warning: error finding products in DB\n")
			goto sleeplabel
		}

		for _, prod := range products {
			subscriptions := []domain.Subscription{}
			var err error
			produ := Product{
				ASIN:        prod.ASIN,
				URL:         prod.URL,
				Marketplace: prod.Marketplace,
			}

			// fetchData
			data, err := FetchProductData(produ)
			if err != nil {
				log.Printf("Warning: error fetching product: %#v\n", prod)
				continue
			}

			// find last data for product
			lastData := domain.ProductData{}
			err = goes.DB.Order("created_at DESC").Where("product_id = ?", prod.ID).First(&lastData).Error
			if err != nil {
				log.Printf("Warning: error finding product last data: %#v\n", prod)
				continue
			}

			//     save product data
			if data.Price != lastData.Price {
				// save product data
				newData := domain.ProductData{}
				createProductDataCmd := productdata.Create{
					Title:     data.Title,
					Price:     data.Price,
					Currency:  data.Currency,
					ProductID: prod.ID,
				}
				_, err = goes.Call(createProductDataCmd, &newData, nil)
				if err != nil {
					log.Printf("Warning: error saving product new data: %#v\n", newData)
					continue
				}

				err = goes.DB.Where("product_id = ?", prod.ID).Find(&subscriptions).Error
				if err != nil {
					log.Printf("Warning: error finding subscription for product: %#v\n", prod)
					continue
				}

				// send notification for each subscriptions
				for _, sub := range subscriptions {
					if sub.Notification == true {
						chat := domain.Chat{BaseAggregate: goes.BaseAggregate{ID: sub.ChatID}}

						err = goes.DB.First(&chat).Error
						if err != nil {
							log.Printf("Warning: error finding chat for subscription: %#v\n", sub)
							continue
						}

						tgChat := &tb.Chat{ID: chat.TelegramID}
						Bot.Send(tgChat, fmt.Sprintf(`Price changed for: %s
				- old price: %f
				- new price: %f
				-> %s
				`, newData.Title, lastData.Price, newData.Price, prod.URL))

					}
				}
				// TODO: send webhook
			}

			time.Sleep(time.Duration(util.RandomInt(10, 16)) * time.Second)

		}
		// for each product
		//   check for changes
		//   if changes:

		//     for each subscription:
		//       // send notification (and webhook if webhook != nil)
		//   sleep(10s)
		// sleep 10min
		log.Printf("scraping round completed")

	sleeplabel:
		time.Sleep(time.Duration(util.RandomInt(6, 8)) * time.Minute)
	}
}
