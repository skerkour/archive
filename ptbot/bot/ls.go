package bot

import (
	"fmt"

	tb "github.com/tucnak/telebot"
	"github.com/z0mbie42/goes"
	"gitlab.com/z0mbie42/ptbot/domain"
)

func HandleLsCmd(message *tb.Message) {
	dialog := GetChatDialog(message.Chat)
	subscriptions := []domain.Subscription{}

	err := goes.DB.Where("chat_id = ?", dialog.Chat.ID).Find(&subscriptions).Error
	if err != nil {
		Bot.Reply(message, "error, aborted")
		return
	}
	if len(subscriptions) == 0 {
		Bot.Reply(message, "No active subscription")
		return

	}

	ret := "Subscriptions:\n"
	for _, sub := range subscriptions {
		prod := domain.Product{}
		data := domain.ProductData{}
		err = goes.DB.Model(sub).Related(&prod).Error
		if err != nil {
			Bot.Reply(message, "error, aborted")
			return
		}
		err = goes.DB.Model(&prod).Related(&data).Error
		if err != nil {
			Bot.Reply(message, "error, aborted")
			return
		}
		notif := ""
		if sub.Notification == true {
			notif += "notification"
		}
		if sub.Webhook != nil {
			if sub.Notification {
				notif += " + "
			}
			notif += "webhook"
		}
		ret += fmt.Sprintf("- %s = %f -> %s -> %s\n", data.Title, data.Price, prod.URL, notif)
	}

	Bot.Reply(message, ret)
}
