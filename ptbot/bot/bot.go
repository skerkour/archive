package bot

import (
	"fmt"
	"log"
	"strings"
	"time"

	tb "github.com/tucnak/telebot"
	"github.com/z0mbie42/goes"
	"gitlab.com/z0mbie42/ptbot/config"
	"gitlab.com/z0mbie42/ptbot/domain"
	"gitlab.com/z0mbie42/ptbot/domain/product"
	"gitlab.com/z0mbie42/ptbot/domain/productdata"
	"gitlab.com/z0mbie42/ptbot/domain/subscription"
	"gitlab.com/z0mbie42/ptbot/service/validator"
)

var Bot *tb.Bot

var NotificationInlineBtn = tb.InlineButton{
	Unique: "notification",
	Data:   "notification",
	Text:   "notification",
}

var WebhookInlineBtn = tb.InlineButton{
	Unique: "webhook",
	Data:   "webhook",
	Text:   "webhook",
}

var BothInlineBtn = tb.InlineButton{
	Unique: "both",
	Data:   "both",
	Text:   "both",
}

func Start() error {
	var err error

	Bot, err = tb.NewBot(tb.Settings{
		Token:  config.Config.TelegramBotToken,
		Poller: &tb.LongPoller{Timeout: 10 * time.Second},
	})

	if err != nil {
		return err
	}

	Bot.Handle("/start", HandleHelpCmd)
	Bot.Handle("/subscribe", HandleSubscribeCmd)
	Bot.Handle("/ls", HandleLsCmd)
	Bot.Handle("/delete", HandleDeleteCmd)
	Bot.Handle("/cancel", HandleCancelCmd)
	Bot.Handle("/help", HandleHelpCmd)
	Bot.Handle(&NotificationInlineBtn, HandleNotificationInlineBtn)
	Bot.Handle(&WebhookInlineBtn, HandleWebhookInlineBtn)
	Bot.Handle(&BothInlineBtn, HandleBothInlineBtn)

	Bot.Handle(tb.OnText, HandleText)

	log.Println("Authorized on account:", Bot.Me.Username)

	Bot.Start()
	return nil
}

func HandleNotificationInlineBtn(callback *tb.Callback) {
	var err error

	dialog := GetChatDialog(callback.Message.Chat)
	currentState := dialog.FSM.Current()
	log.Printf("[%d]: %s\n", callback.Message.Chat.ID, currentState)
	if currentState != "asking_for_subscription_type" {
		Bot.Send(callback.Message.Chat, "State is not valid, command canceled")
		dialog.FSM.Event("cancel_called")
		return
	}

	// TODO:
	tx := goes.DB.Begin()

	productToMonitor := &domain.Product{}
	sub := &domain.Subscription{}
	data := &domain.ProductData{}

	tx.Where("asin = ?", dialog.Product.ASIN).First(productToMonitor)
	if productToMonitor.ID == "" {
		// create product if its necessary
		createProductCmd := product.Create{
			ASIN:        dialog.Product.ASIN,
			URL:         dialog.Product.URL,
			Marketplace: dialog.Product.Marketplace,
		}
		_, err = goes.CallTx(tx, createProductCmd, productToMonitor, nil)
		if err != nil {
			tx.Rollback()
			panic(err)
		}
	}

	// create subscription
	createSubCmd := subscription.Create{
		Webhook:      dialog.Webhook,
		Notification: true,
		ProductID:    productToMonitor.ID,
		ChatID:       dialog.Chat.ID,
	}
	_, err = goes.CallTx(tx, createSubCmd, sub, nil)
	if err != nil {
		tx.Rollback()
		panic(err)
	}

	// fetch product data
	productData, err := FetchProductData(dialog.Product)
	if err != nil {
		tx.Rollback()
		panic(err)
	}

	// save product data
	createProductDataCmd := productdata.Create{
		Title:     productData.Title,
		Price:     productData.Price,
		Currency:  productData.Currency,
		ProductID: productToMonitor.ID,
	}
	_, err = goes.CallTx(tx, createProductDataCmd, data, nil)
	if err != nil {
		tx.Rollback()
		panic(err)
	}
	// send success with the title of the product

	if err = tx.Commit().Error; err != nil {
		tx.Rollback()
		panic(err)
	}
	dialog.FSM.Event("notification_chosen")
	Bot.Respond(callback, &tb.CallbackResponse{CallbackID: callback.ID})
	Bot.Edit(callback.Message, fmt.Sprintf("Success, you are now subscribed to %s price updates", data.Title))
	log.Printf("[%d] -> %s\n", callback.Message.Chat.ID, dialog.FSM.Current())
}

func HandleWebhookInlineBtn(callback *tb.Callback) {
	dialog := GetChatDialog(callback.Message.Chat)
	currentState := dialog.FSM.Current()
	log.Printf("[%d]: %s\n", callback.Message.Chat.ID, currentState)
	Bot.Respond(callback, &tb.CallbackResponse{CallbackID: callback.ID})
	if currentState != "asking_for_subscription_type" {
		Bot.Send(callback.Message.Chat, "State is not valid, command canceled")
		dialog.FSM.Event("cancel_called")
		return
	}

	// TODO
	dialog.FSM.Event("cancel_called")
	Bot.Edit(callback.Message, "not implemented yet, aborted")
	return
	dialog.FSM.Event("webhook_url_sent")
	Bot.Edit(callback.Message, "Please enter your webhook URL")
	log.Printf("[%d] -> %s\n", callback.Message.Chat.ID, dialog.FSM.Current())
}

func HandleBothInlineBtn(callback *tb.Callback) {
	dialog := GetChatDialog(callback.Message.Chat)
	currentState := dialog.FSM.Current()
	log.Printf("[%d]: %s\n", callback.Message.Chat.ID, currentState)
	Bot.Respond(callback, &tb.CallbackResponse{CallbackID: callback.ID})
	if currentState != "asking_for_subscription_type" {
		Bot.Send(callback.Message.Chat, "State is not valid, command canceled")
		dialog.FSM.Event("cancel_called")
		return
	}

	// TODO
	dialog.FSM.Event("cancel_called")
	Bot.Edit(callback.Message, "not implemented yet, aborted")
	return
	dialog.FSM.Event("both_chosen")
	Bot.Edit(callback.Message, "Please enter your webhook URL")
	log.Printf("[%d] -> %s\n", callback.Message.Chat.ID, dialog.FSM.Current())
}

func HandleSubscribeCmd(message *tb.Message) {
	dialog := GetChatDialog(message.Chat)
	currentState := dialog.FSM.Current()
	log.Printf("[%d]: %s\n", message.Chat.ID, currentState)
	dialog.FSM.Event("subscribe_called")
	Bot.Reply(message, "Please enter your Amazon product URL")
	log.Printf("[%d] -> %s\n", message.Chat.ID, dialog.FSM.Current())
}

func HandleText(message *tb.Message) {
	dialog := GetChatDialog(message.Chat)
	currentState := dialog.FSM.Current()
	log.Printf("[%d]: %s\n", message.Chat.ID, currentState)

	switch currentState {
	case "asking_for_product_url":
		productURL := strings.TrimSpace(message.Text)
		product, err := ExtractProduct(productURL)
		if err != nil {
			dialog.FSM.Event("product_url_is_not_valid")
			Bot.Reply(message, "URL is not valid. Command aborted")
			break
		}
		dialog.Product = product
		dialog.FSM.Event("product_url_is_valid")
		// Ask for subscription type
		inlineKeys := [][]tb.InlineButton{
			[]tb.InlineButton{NotificationInlineBtn, WebhookInlineBtn, BothInlineBtn},
		}
		Bot.Send(
			message.Chat,
			"Subscription type ?",
			&tb.ReplyMarkup{
				InlineKeyboard: inlineKeys,
			})

	case "asking_for_subscription_type":
		subType := strings.TrimSpace(message.Text)
		if subType != "notification" && subType != "webhook" && subType != "both" {
			dialog.FSM.Event("subscription_type_is_not_valid")
			Bot.Reply(message, "Subscription type is not valid. Command aborted")
			break
		}
		switch subType {
		case "notfication":
			dialog.FSM.Event("notification_chosen")
			Bot.Reply(message, "Success")
			// Todo, save product
		case "webhook":
			dialog.FSM.Event("webhook_chosen")
			Bot.Reply(message, "Please enter your webhook URL")
		case "both":
			dialog.FSM.Event("both_chosen")
			Bot.Reply(message, "Please enter your webhook URL")
		}

	case "asking_for_webhook_url":
		webhookURL := strings.TrimSpace(message.Text)
		err := validator.WebhookURL(webhookURL)
		if err != nil {
			Bot.Reply(message, "URL is not valid. Command aborted")
			break
		}
		dialog.Webhook = &webhookURL
		dialog.FSM.Event("webhook_url_sent")
		Bot.Reply(message, "Success")
		// TODO: save product

	default:
		Bot.Reply(message, "Command not found. Use /help to list all available commands")
	}

	log.Printf("[%d] -> %s\n", message.Chat.ID, dialog.FSM.Current())
}

func HandleCancelCmd(message *tb.Message) {
	dialog := GetChatDialog(message.Chat)
	currentState := dialog.FSM.Current()
	log.Printf("[%d]: %s\n", message.Chat.ID, currentState)
	dialog.FSM.Event("cancel_called")

	switch currentState {
	case "asking_for_product_url", "asking_for_subscription_type", "asking_for_webhook_url":
		Bot.Reply(message, "/subscribe command canceled")

	default:
		Bot.Reply(message, "No active command to cancel. I wasn't doing anything anyway. Zzzzz...")
	}

	log.Printf("[%d] -> %s\n", message.Chat.ID, dialog.FSM.Current())
}

func HandleHelpCmd(message *tb.Message) {
	Bot.Reply(
		message,
		`Hello!
Amazon Price Tracker lets you subscribe to Amazon product updates. You can receive a notfication, a webhook or both.
Here are the available commands:
- /subscribe - Start tracking the price of a product
- /ls - List subscriptions
- /rm - Delete subscription
- /cancel - Cancel the current opreation
- /help - Display help`,
		&tb.SendOptions{ParseMode: tb.ModeMarkdown})
}
