package config

import (
	"fmt"
	"os"

	"github.com/joho/godotenv"
	"github.com/z0mbie42/goes"
	"gitlab.com/z0mbie42/ptbot/domain"
)

var Config Configuration

var RequiredEnvVars = []string{
	"DATABASE_URL",
	"GO_ENV",
	"TELEGRAM_BOT_TOKEN",
}

type Configuration struct {
	DatabaseURL      string `json:"database_url"`
	TelegramBotToken string `json:"telegram_bot_token"`
	GoEnv            string `json:"go_env"`
}

func CheckEnv() error {
	for _, v := range RequiredEnvVars {
		if os.Getenv(v) == "" {
			return fmt.Errorf("Missing env variable: %s", v)
		}
	}

	return nil
}

func Init() error {
	godotenv.Load()
	CheckEnv()

	Config.DatabaseURL = os.Getenv("DATABASE_URL")
	Config.TelegramBotToken = os.Getenv("TELEGRAM_BOT_TOKEN")
	Config.GoEnv = os.Getenv("GO_ENV")

	displayDBLogs := true
	if Config.GoEnv == "production" {
		displayDBLogs = false
	}
	err := goes.InitDB(Config.DatabaseURL, displayDBLogs)
	if err != nil {
		return err
	}

	goes.Register(&domain.Chat{})

	goes.Register(&domain.Message{})

	goes.Register(&domain.Subscription{})

	goes.Register(&domain.Product{})

	goes.Register(&domain.ProductData{})

	return nil
}
