package bot

import (
	"log"

	tb "github.com/tucnak/telebot"
)

func HandleDeleteCmd(message *tb.Message) {
	// TODO
	dialog := GetChatDialog(message.Chat)
	currentState := dialog.FSM.Current()
	log.Printf("[%d]: %s\n", message.Chat.ID, currentState)
	dialog.FSM.Event("cancel_called")
	Bot.Reply(message, "not implemented yet, aborted")
}
