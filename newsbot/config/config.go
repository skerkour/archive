package config

import (
	"errors"
	"os"
	"strconv"

	"github.com/algolia/algoliasearch-client-go/algoliasearch"
	"github.com/go-telegram-bot-api/telegram-bot-api"
	"github.com/jinzhu/gorm"
	_ "github.com/jinzhu/gorm/dialects/postgres"
	"github.com/joho/godotenv"
)

type Config struct {
	DatabaseURL      string
	TelegramAdmin    int64
	TelegramBotToken string
	GoEnv            string
	AlgoliaAppID     string
	AlgoliaAPIKey    string
	AlgoliaIndex     string

	Index algoliasearch.Index
	Bot   *tgbotapi.BotAPI
	DB    *gorm.DB
}

func GetConfig() (Config, error) {
	var ret Config
	var err error

	godotenv.Load()

	ret.DB, err = gorm.Open("postgres", os.Getenv("DATABASE_URL"))
	if err != nil {
		return ret, err
	}

	adminStr := os.Getenv("TELEGRAM_ADMIN")
	admin, err := strconv.ParseInt(adminStr, 10, 64)
	if err != nil {
		return ret, err
	}
	ret.TelegramAdmin = admin

	ret.TelegramBotToken = os.Getenv("TELEGRAM_BOT_TOKEN")
	if ret.TelegramBotToken == "" {
		return ret, errors.New("TELEGRAM_BOT_TOKEN is missing")
	}

	ret.Bot, err = tgbotapi.NewBotAPI(ret.TelegramBotToken)
	if err != nil {
		return ret, err
	}

	ret.GoEnv = os.Getenv("GO_ENV")

	ret.AlgoliaAppID = os.Getenv("ALGOLIA_APP_ID")
	if ret.AlgoliaAppID == "" {
		ret.AlgoliaAppID = "UJ5WYC0L7X"
	}

	ret.AlgoliaAPIKey = os.Getenv("ALGOLIA_API_KEY")
	if ret.AlgoliaAPIKey == "" {
		ret.AlgoliaAPIKey = "8ece23f8eb07cd25d40262a1764599b1"
	}

	ret.AlgoliaIndex = os.Getenv("ALGOLIA_INDEX")
	if ret.AlgoliaIndex == "" {
		ret.AlgoliaIndex = "Item_production_ordered"
	}

	client := algoliasearch.NewClient(ret.AlgoliaAppID, ret.AlgoliaAPIKey)
	ret.Index = client.InitIndex(ret.AlgoliaIndex)

	return ret, nil
}
