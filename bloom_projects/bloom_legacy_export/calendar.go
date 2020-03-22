package main

import (
	"encoding/json"
	"errors"
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"path/filepath"
)

type Event struct {
	Id string `json:"id"`
}

type CalendarRes = []Event
type CalendarDataRes = []map[string]interface{}

func ExportCalendar(client *http.Client) error {
	var apiRes ApiRes
	var eventsRes CalendarRes
	var eventsDataRes CalendarDataRes

	dirPath := filepath.Join(ExportFolder, CalendarFolder)
	err := os.MkdirAll(dirPath, os.ModePerm)
	if err != nil {
		return err
	}

	res, err := client.Get("https://legacy.bloom.sh/api/calendar/v1/events")
	if err != nil {
		return err
	}
	defer res.Body.Close()

	resBody, err := ioutil.ReadAll(res.Body)
	if err != nil {
		return err
	}

	err = json.Unmarshal(resBody, &apiRes)
	if err != nil {
		return err
	}

	if apiRes.Error != nil {
		return errors.New(apiRes.Error.Message)
	}

	err = json.Unmarshal(apiRes.Data, &eventsRes)
	if err != nil {
		return err
	}

	err = json.Unmarshal(apiRes.Data, &eventsDataRes)
	if err != nil {
		return err
	}

	for i, event := range eventsRes {
		if err = exportEvent(event.Id, eventsDataRes[i]); err != nil {
			return err
		}
	}

	return err
}

func exportEvent(id string, event map[string]interface{}) error {
	eventPath := filepath.Join(ExportFolder, CalendarFolder, fmt.Sprintf("%s.json", id))
	data, err := json.MarshalIndent(event, "", "  ")
	if err != nil {
		return err
	}

	err = ioutil.WriteFile(eventPath, data, 0644)
	if err != nil {
		return err
	}
	return nil
}
