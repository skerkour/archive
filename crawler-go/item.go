package crawler

// The main goal in scraping is to extract structured data from unstructured
// sources, typically, web pages. Scrapy spiders can return the extracted data
// as Python dicts. While convenient and familiar, Python dicts lack structure:
// it is easy to make a typo in a field name or return inconsistent data,
// especially in a larger project with many spiders.
//
// To define common output data format Scrapy provides the Item class. Item
// objects are simple containers used to collect the scraped data. They provide
// a dictionary-like API with a convenient syntax for declaring their available
// fields.
type Item interface {
	// unique id for object to verify if it has been processed
	ID() string
	// process the item g. save in database
	Process() error
}
