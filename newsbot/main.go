package main

import (
	"flag"
	"fmt"
	"net/http"
	"os"
	"time"

	"github.com/algolia/algoliasearch-client-go/algoliasearch"
	"github.com/bloom42/astro-go"
	"github.com/bloom42/astro-go/log"
	"github.com/bloom42/newsbot/bot"
	"github.com/bloom42/newsbot/config"
	"github.com/go-telegram-bot-api/telegram-bot-api"
)

func SendSummary(conf config.Config) error {
	res, err := conf.Index.Search("", algoliasearch.Map{
		"hitsPerPage": 12, // retrieve the last 12 stories
		"tagFilters":  "story",
		// from the last 12 hours
		"numericFilters": fmt.Sprintf("created_at_i>%v", time.Now().Add(-12*time.Hour).Unix()),
	})
	if err != nil {
		return err
	}

	subscriptions := []bot.Subscription{}
	err = conf.DB.Find(&subscriptions).Error
	if err != nil {
		return err
	}

	// create summary
	text := ""
	for i, hit := range res.Hits {
		url := hit["url"]
		if url == nil {
			url = fmt.Sprintf("https://news.ycombinator.com/item?id=%v", hit["objectID"])
		}
		text += fmt.Sprintf("[#%d] %v\n%v\n\n\n", i+1, hit["title"], url)
	}
	// send summary to all subscriber
	for _, subscription := range subscriptions {
		if subscription.IsActive == false {
			continue
		}

		msg := tgbotapi.NewMessage(subscription.TelegramChatID, text)
		_, err = conf.Bot.Send(msg)
		if err != nil {
			log.Error(err.Error())
		}

	}

	return nil
}

func main() {
	var isCron = flag.Bool("cron", false, "use it to run the cron action")
	flag.Parse()

	port := os.Getenv("PORT")
	if port == "" {
		port = "8080"
	}

	log.Config(
		astro.SetFormatter(astro.NewConsoleFormatter()),
	)
	conf, err := config.GetConfig()
	if err != nil {
		log.Fatal(err.Error())
	}
	defer conf.DB.Close()

	err = conf.DB.AutoMigrate(&bot.Subscription{}).Error
	if err != nil {
		log.Error(err.Error())
	}

	if conf.GoEnv == "debug" {
		conf.Bot.Debug = true
		log.Config(astro.SetLevel(astro.DebugLevel))
	} else {
		log.Config(astro.SetLevel(astro.InfoLevel))
	}

	log.With("config", conf).Debug("config successfully loaded")
	if *isCron {
		log.Debug("cron ran")
		err = SendSummary(conf)
		if err != nil {
			log.Error(err.Error())
		}
		return
	}

	// listen for messages
	_, err = conf.Bot.SetWebhook(tgbotapi.NewWebhook("https://hnbot-production.herokuapp.com/" + conf.Bot.Token))
	if err != nil {
		log.Fatal(err.Error())
	}
	info, err := conf.Bot.GetWebhookInfo()
	if err != nil {
		log.Fatal(err.Error())
	}
	if info.LastErrorDate != 0 {
		log.Errorf("Telegram callback failed: %s", info.LastErrorMessage)
	}
	updates := conf.Bot.ListenForWebhook("/" + conf.Bot.Token)
	go http.ListenAndServe(":"+port, nil)

	log.Info("listenning for messages...")
	for update := range updates {
		if update.Message == nil {
			continue
		}

		log.With("username", update.Message.From.UserName, "message", update.Message.Text).
			Debug("message received")

		err := bot.HandleMessage(conf, update.Message)
		if err != nil {
			log.Error(err.Error())
		}
	}
}
