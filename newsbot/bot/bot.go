package bot

import (
	"errors"
	"fmt"
	"strings"

	"github.com/bloom42/astro-go/log"
	"github.com/bloom42/newsbot/config"
	"github.com/go-telegram-bot-api/telegram-bot-api"
	"github.com/jinzhu/gorm"
)

const HelpMsg = `
newsbot helps you manage the information overflow: automated HN curation every 12 hours.

You subscription is currently: %s

Available commands:
/subscribe - Subscribe to two daily notifications
/unsubscribe - Unsubscribe
/help - Display help

See https://github.com/bloom42/newsbot for more information
`

const ActiveMsg = "✅ Active"
const InactiveMsg = "❌ Inactive"
const SuccessMsg = "✅ Success"
const ErrorMsg = "❌ Error"

type Subscription struct {
	gorm.Model
	TelegramChatID int64 `gorm:"index:tg_chat_id"`
	IsActive       bool
}

func HandleMessage(conf config.Config, msg *tgbotapi.Message) error {
	message := strings.ToLower(strings.TrimSpace(msg.Text))
	var err error

	switch message {
	case "/subscribe":
		err = Subscribe(conf, msg)
	case "/unsubscribe":
		err = Unsubscribe(conf, msg)
	case "/start", "/help", "help":
		err = SendHelp(conf, msg)
	default:
		err = fmt.Errorf("command not found: %s", msg.Text)
	}
	if err != nil {
		err = SendError(conf, msg, err.Error())
	}

	return err
}

func Subscribe(conf config.Config, msg *tgbotapi.Message) error {
	subscription, err := FindOrCreateByTGID(conf, msg.Chat.ID)
	if err != nil {
		log.Error(err.Error())
		return errors.New("subscribing")
	}

	subscription.IsActive = true
	err = conf.DB.Save(&subscription).Error
	if err != nil {
		log.Error(err.Error())
		return errors.New("subscribing")
	}

	err = SendSuccess(conf, msg)
	return err
}

func Unsubscribe(conf config.Config, msg *tgbotapi.Message) error {
	subscription, err := FindOrCreateByTGID(conf, msg.Chat.ID)
	if err != nil {
		log.Error(err.Error())
		return errors.New("unsubscribing")
	}

	subscription.IsActive = false
	err = conf.DB.Save(&subscription).Error
	if err != nil {
		log.Error(err.Error())
		return errors.New("unsubscribing")
	}

	err = SendSuccess(conf, msg)
	return nil
}

func SendHelp(conf config.Config, msg *tgbotapi.Message) error {
	var status string

	subscription, err := FindOrCreateByTGID(conf, msg.Chat.ID)
	if err != nil {
		log.Error(err.Error())
		return errors.New("unknown")

	}

	if subscription.IsActive {
		status = ActiveMsg
	} else {
		status = InactiveMsg
	}

	message := tgbotapi.NewMessage(msg.Chat.ID, fmt.Sprintf(HelpMsg, status))
	message.ReplyToMessageID = msg.MessageID
	_, err = conf.Bot.Send(message)
	return err
}

func SendError(conf config.Config, msg *tgbotapi.Message, errorMsg string) error {
	message := tgbotapi.NewMessage(msg.Chat.ID, fmt.Sprintf("%s: %s", ErrorMsg, errorMsg))
	message.ReplyToMessageID = msg.MessageID
	_, err := conf.Bot.Send(message)
	return err
}

func SendSuccess(conf config.Config, msg *tgbotapi.Message) error {
	message := tgbotapi.NewMessage(msg.Chat.ID, SuccessMsg)
	message.ReplyToMessageID = msg.MessageID
	_, err := conf.Bot.Send(message)
	return err
}

func FindOrCreateByTGID(conf config.Config, chatID int64) (Subscription, error) {
	ret := Subscription{TelegramChatID: chatID}
	var err error

	err = conf.DB.Where("telegram_chat_id = ?", chatID).First(&ret).Error

	if err != nil {
		if gorm.IsRecordNotFoundError(err) {
			err = conf.DB.Create(&ret).Error
		}
	}
	return ret, err
}
