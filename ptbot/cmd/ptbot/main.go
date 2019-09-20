package main

import (
	"flag"
	"fmt"
	"log"

	"gitlab.com/z0mbie42/ptbot/bot"
	"gitlab.com/z0mbie42/ptbot/config"
)

func main() {
	dumpFSM := flag.Bool("fsm", false, "dump Dialogs FSM to stdout")
	flag.Parse()

	err := config.Init()
	if err != nil {
		log.Fatal(err)
	}

	if *dumpFSM == true {
		fmt.Println(bot.DumpDialogs())
	} else {
		go bot.Scraper()
		bot.Start()
	}

	/*

		bot, err := tgbotapi.NewBotAPI(config.Config.TelegramBotToken)
		if err != nil {
			log.Panic(err)
		}

		if config.Config.GoEnv != "production" {
			bot.Debug = true
		}

		log.Printf("Authorized on account %s", bot.Self.UserName)

		u := tgbotapi.NewUpdate(0)
		u.Timeout = 60

		updates, err := bot.GetUpdatesChan(u)

		for update := range updates {
			if update.Message == nil {
				continue
			}
			var msgText string
			var productData amazon.ProductData
			var err error

			log.Printf("[%s] %s", update.Message.From.UserName, update.Message.Text)

			url := strings.TrimSpace(update.Message.Text)
			product, err := amazon.ExtractProduct(url)
			if err != nil {
				msgText = err.Error()
				goto send
			}

			productData, err = amazon.FetchProductData(product)
			if err != nil {
				msgText = err.Error()
				goto send
			}

			msgText = fmt.Sprintf("%#v, data: %#v\n", product, productData)

		send:
			msg := tgbotapi.NewMessage(update.Message.Chat.ID, msgText)
			msg.ReplyToMessageID = update.Message.MessageID
			bot.Send(msg)
		}

	*/

}
