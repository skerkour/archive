package main

import (
	"fmt"
	"os"
	"strings"

	"gitlab.com/z0mbie42/ptbot/bot"
)

func Usage() {
	fmt.Println("./scraper [URL]")
	os.Exit(0)
}

func main() {
	if len(os.Args) != 2 {
		Usage()
	}

	url := strings.TrimSpace(os.Args[1])
	product, err := bot.ExtractProduct(url)
	if err != nil {
		panic(err)
	}

	productData, err := bot.FetchProductData(product)
	if err != nil {
		panic(err)
	}
	fmt.Printf("Product: %#v\nData: %#v\n", product, productData)
}
