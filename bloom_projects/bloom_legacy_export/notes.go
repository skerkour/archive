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

type Note struct {
	Id string `json:"id"`
}

type NotesRes = []Note
type NotesDataRes = []map[string]interface{}

func ExportNotes(client *http.Client) error {
	var apiRes ApiRes
	var notesRes NotesRes
	var notesDataRes NotesDataRes

	dirPath := filepath.Join(ExportFolder, NotesFolder)
	err := os.MkdirAll(dirPath, os.ModePerm)
	if err != nil {
		return err
	}

	res, err := client.Get("https://legacy.bloom.sh/api/notes/v1/notes")
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

	err = json.Unmarshal(apiRes.Data, &notesRes)
	if err != nil {
		return err
	}

	err = json.Unmarshal(apiRes.Data, &notesDataRes)
	if err != nil {
		return err
	}

	for i, note := range notesRes {
		if err = exportNote(note.Id, notesDataRes[i]); err != nil {
			return err
		}
	}

	return err
}

func exportNote(id string, note map[string]interface{}) error {
	NotePath := filepath.Join(ExportFolder, NotesFolder, fmt.Sprintf("%s.json", id))
	data, err := json.MarshalIndent(note, "", "  ")
	if err != nil {
		return err
	}

	err = ioutil.WriteFile(NotePath, data, 0644)
	if err != nil {
		return err
	}
	return nil
}
