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

type Contact struct {
	Id string `json:"id"`
}

type ContactsRes = []Contact
type ContactsDataRes = []map[string]interface{}

func ExportContacts(client *http.Client) error {
	var apiRes ApiRes
	var contactsRes ContactsRes
	var contactsDataRes ContactsDataRes

	dirPath := filepath.Join(ExportFolder, ContactsFolder)
	err := os.MkdirAll(dirPath, os.ModePerm)
	if err != nil {
		return err
	}

	res, err := client.Get("https://legacy.bloom.sh/api/contacts/v1/contacts")
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

	err = json.Unmarshal(apiRes.Data, &contactsRes)
	if err != nil {
		return err
	}

	err = json.Unmarshal(apiRes.Data, &contactsDataRes)
	if err != nil {
		return err
	}

	for i, contact := range contactsRes {
		if err = exportContact(contact.Id, contactsDataRes[i]); err != nil {
			return err
		}
	}

	return err
}

func exportContact(id string, contact map[string]interface{}) error {
	contactPath := filepath.Join(ExportFolder, ContactsFolder, fmt.Sprintf("%s.json", id))
	data, err := json.MarshalIndent(contact, "", "  ")
	if err != nil {
		return err
	}

	err = ioutil.WriteFile(contactPath, data, 0644)
	if err != nil {
		return err
	}
	return nil
}
