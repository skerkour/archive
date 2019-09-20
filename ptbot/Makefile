.PHONY: dev deploy dep fsm

dep:
	godep save ./...

dev:
	go run cmd/ptbot/main.go

deploy:
	git push heroku master

fsm:
	go run cmd/ptbot/main.go -fsm > dialogs.dot
	dot -Tpng dialogs.dot > dialogs.png
