package bot

import (
	"github.com/looplab/fsm"
	tb "github.com/tucnak/telebot"
	"github.com/z0mbie42/goes"
	"gitlab.com/z0mbie42/ptbot/domain"
	"gitlab.com/z0mbie42/ptbot/domain/chat"
)

var Chats = map[int64]*Dialog{}

type Dialog struct {
	Chat domain.Chat
	FSM  *fsm.FSM

	Product Product
	Webhook *string
}

func GetChatDialog(tgChat *tb.Chat) *Dialog {
	_, ok := Chats[tgChat.ID]
	if ok != true {
		Chats[tgChat.ID] = NewDialog(tgChat)
	}
	return Chats[tgChat.ID]
}

func NewFSM() *fsm.FSM {
	fsm := fsm.NewFSM(
		"initial",
		fsm.Events{
			{
				Name: "rm_called",
				Src:  []string{"initial"},
				Dst:  "initial",
			},
			{
				Name: "ls_called",
				Src:  []string{"initial"},
				Dst:  "initial",
			},
			{
				Name: "cancel_called",
				Src: []string{
					"initial",
					"asking_for_product_url",
					"asking_for_subscription_type",
					"asking_for_webhook_url",
				},
				Dst: "initial",
			},
			{
				Name: "help_called",
				Src:  []string{"initial"},
				Dst:  "initial",
			},
			{
				Name: "subscribe_called",
				Src:  []string{"initial"},
				Dst:  "asking_for_product_url",
			},
			{
				Name: "product_url_is_not_valid",
				Src:  []string{"asking_for_product_url"},
				Dst:  "initial",
			},
			{
				Name: "product_url_is_valid",
				Src:  []string{"asking_for_product_url"},
				Dst:  "asking_for_subscription_type",
			},
			{
				Name: "notification_chosen",
				Src:  []string{"asking_for_subscription_type"},
				Dst:  "initial",
			},
			{
				Name: "webhook_chosen",
				Src:  []string{"asking_for_subscription_type"},
				Dst:  "asking_for_webhook_url",
			},
			{
				Name: "both_chosen",
				Src:  []string{"asking_for_subscription_type"},
				Dst:  "asking_for_webhook_url",
			},
			{
				Name: "subscription_type_is_not_valid",
				Src:  []string{"asking_for_subscription_type"},
				Dst:  "initial",
			},
			{
				Name: "webhook_url_sent",
				Src:  []string{"asking_for_webhook_url"},
				Dst:  "initial",
			},
		},
		fsm.Callbacks{},
	)
	return fsm
}

func NewDialog(tgChat *tb.Chat) *Dialog {

	currentChat := domain.Chat{}
	goes.DB.Where("telegram_id = ?", tgChat.ID).First(&currentChat)
	if currentChat.ID == "" {
		createChatCmd := chat.Create{
			TelegramID: tgChat.ID,
			Title:      tgChat.Title,
			Username:   tgChat.Username,
			Type:       string(tgChat.Type),
		}
		_, err := goes.Call(createChatCmd, &currentChat, nil)
		if err != nil {
			// TODO: handle err
			panic(err)
		}

	}

	ret := Dialog{
		FSM:  NewFSM(),
		Chat: currentChat,
	}

	return &ret
}

func DumpDialogs() string {
	return fsm.Visualize(NewFSM())
}
