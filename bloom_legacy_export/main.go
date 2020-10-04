package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"net/http"
	"os"
	"strings"

	"gitlab.com/bloom42/libs/rz-go"
	"gitlab.com/bloom42/libs/rz-go/log"
)

type ApiRes struct {
	Data  json.RawMessage `json:"data"`
	Error *ApiError       `json:"error"`
}

type ApiError struct {
	Message string `json:"message"`
}

func AskRemoveExportFolder() (string, error) {
	reader := bufio.NewReader(os.Stdin)
	res, err := reader.ReadString('\n')
	if err != nil {
		return "", err
	}

	return strings.ToLower(strings.TrimSpace(res)), nil
}

func main() {
	log.SetLogger(log.With(rz.Formatter(rz.FormatterCLI())))
	client := &http.Client{}

	fmt.Printf("The %s folder will be deleted, continue ? (y/n) ", ExportFolder)
	resRemoveExportFolder, err := AskRemoveExportFolder()
	if err != nil {
		log.Fatal("Error reading input", rz.Error("Error", err))
	}
	if resRemoveExportFolder != "y" {
		log.Error("Aborting")
		os.Exit(0)
	}

	err = os.RemoveAll(ExportFolder)
	if err != nil {
		log.Fatal("Error removing export folder", rz.Error("Error", err))
	}

	username, password, err := AskCredentials()
	if err != nil {
		log.Fatal("Error signing in", rz.Error("Error", err))
	}

	token, err := Authenticate(client, username, password)
	if err != nil {
		log.Fatal("Error signing in", rz.Error("Error", err))
	}

	client = &http.Client{Transport: AuthTransport(nil, token)}

	log.Info("Exporting Notes")
	if err = ExportNotes(client); err != nil {
		log.Fatal("Error exporting notes", rz.Error("Error", err))
	}
	log.Info("Notes sucessfully exported")

	log.Info("Exporting Contacts")
	if err = ExportContacts(client); err != nil {
		log.Fatal("Error exporting contacts", rz.Error("Error", err))
	}
	log.Info("Contacts sucessfully exported")

	log.Info("Exporting Calendar")
	if err = ExportCalendar(client); err != nil {
		log.Fatal("Error exporting calendar", rz.Error("Error", err))
	}
	log.Info("Calendar sucessfully exported")

	log.Info("Exporting Drive. It may take some time.")
	if err = ExportDrive(client); err != nil {
		log.Fatal("Error exporting Drive", rz.Error("Error", err))
	}
	log.Info("Drive sucessfully exported")
}
