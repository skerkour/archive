# How to use
first, create a config file
    config.json
according to the configExample.json file

    cd bot_puller/
    go run bot.go

In another shell
    cd server/
    go run *.go

In a third shell
    curl --data "kind=buy&amount=1&token=az" localhost:8080/orders
