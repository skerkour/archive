package rss

import (
	"encoding/json"
	"errors"
	"fmt"
	"io/ioutil"
	"log"
	"net/url"
	"os"
	"os/exec"
	"path/filepath"
	"runtime"
	"sort"
	"strconv"
	"time"
	"unicode"

	"github.com/SlyMarbo/rss"
	"github.com/gdamore/tcell"
	"github.com/rivo/tview"
)

// Config represents the configuration file
type Config struct {
	Feeds []string `json:"feeds"`
}

type FeedItem struct {
	FeedName string
	Title    string
	URL      string
	Date     time.Time
}

var (
	UIList *tview.List
	UIApp  *tview.Application
)

// Run the RSS command
func Run(args []string) (err error) {
	config, err := loadConfig()
	if err != nil {
		return
	}

	items := []FeedItem{}
	fetchedItems := make(chan []FeedItem)

	for _, feedUrl := range config.Feeds {
		go fetchFeed(feedUrl, fetchedItems)
	}

	for range config.Feeds {
		fetched := <-fetchedItems
		items = append(items, fetched...)
	}
	close(fetchedItems)

	sort.Slice(items, func(i, j int) bool {
		return items[i].Date.After(items[j].Date)
	})

	UIApp = tview.NewApplication()
	UIList = tview.NewList()
	titleFormat := feedTitleFormat(items)
	for _, item := range items {
		UIList.AddItem(
			fmt.Sprintf("%s | "+titleFormat+" | %s", item.Date.Format("2006-01-02 15:04"), item.FeedName, item.Title),
			"", '\x00', nil,
		)
	}

	UIList.ShowSecondaryText(false)
	UIList.SetInputCapture(func(event *tcell.EventKey) *tcell.EventKey {
		key := event.Key()
		if key == tcell.KeyEscape {
			UIApp.Stop()
			return nil
		} else if key == tcell.KeyEnter {
			itemIndex := UIList.GetCurrentItem()
			err := openItem(items[itemIndex])
			if err != nil {
				log.Fatal(err)
			}
			return nil
		} else if key == tcell.KeyRune {
			switch unicode.ToLower(event.Rune()) {
			case 'o':
				itemIndex := UIList.GetCurrentItem()
				err := openItem(items[itemIndex])
				if err != nil {
					log.Fatal(err)
				}
				return nil
			case 'q':
				UIApp.Stop()
				return nil
			}
		}
		return event
	})

	err = UIApp.SetRoot(UIList, true).EnableMouse(true).Run()

	return
}

func configDirectory() (string, error) {
	home, err := os.UserHomeDir()
	if err != nil {
		return home, err
	}
	dir := filepath.Join(home, ".rss")
	return dir, nil
}

func configFile() (string, error) {
	home, err := configDirectory()
	if err != nil {
		return home, err
	}
	file := filepath.Join(home, "config.json")
	return file, nil
}

func loadConfig() (ret *Config, err error) {
	configPath, err := configFile()
	if err != nil {
		return
	}

	configData, err := ioutil.ReadFile(configPath)
	if err != nil {
		return
	}

	ret = &Config{}

	err = json.Unmarshal(configData, ret)
	return
}

func openItem(item FeedItem) error {
	var cmd string
	var args []string

	url, err := url.Parse(item.URL)
	if err != nil {
		return err
	}

	if url.Scheme != "http" && url.Scheme != "https" {
		return errors.New("Invaldi URL")
	}

	switch runtime.GOOS {
	case "windows":
		cmd = "cmd"
		args = []string{"/c", "start"}
	case "darwin":
		cmd = "open"
		args = []string{"-gj"}
	default:
		cmd = "xdg-open"
	}

	args = append(args, item.URL)
	return exec.Command(cmd, args...).Start()
}

func feedTitleFormat(items []FeedItem) string {
	maxAlign := 20
	align := 0
	for _, item := range items {
		if len(item.FeedName) < maxAlign && len(item.FeedName) > align {
			align = len(item.FeedName)
		}
	}

	if align == 0 {
		align = maxAlign
	}

	return "%-" + strconv.Itoa(align) + "s"
}

func fetchFeed(feedUrl string, result chan<- []FeedItem) {
	items := []FeedItem{}

	feed, err := rss.Fetch(feedUrl)
	if err != nil {
		log.Fatal(err)
	}

	for _, feedItem := range feed.Items {
		item := FeedItem{
			FeedName: feed.Title,
			Title:    feedItem.Title,
			URL:      feedItem.Link,
			Date:     feedItem.Date,
		}
		items = append(items, item)
	}
	result <- items
}
