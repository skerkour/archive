package main

import (
	"encoding/json"
	"errors"
	"fmt"
	"io"
	"io/ioutil"
	"net/http"
	"os"
	"path/filepath"
)

type Folder struct {
	Id    string `json:"id"`
	Name  string `json:"name"`
	Files []File `json:"files"`
}

type File struct {
	Id   string `json:"id"`
	Name string `json:"name"`
	Type string `json:"type"`
}

type FileUrl struct {
	Url string `json:"url"`
}

func ExportDrive(client *http.Client) error {

	err := exportDriveFolder(client, filepath.Join(ExportFolder, DriveFolder), "")
	if err != nil {
		return err
	}

	return nil
}

func exportDriveFolder(client *http.Client, path, id string) error {
	var apiRes ApiRes
	var folder Folder
	url := "https://legacy.bloom.sh/api/drive/v1/folders"

	if id != "" {
		url = fmt.Sprintf("%s?id=%s", url, id)
	}

	res, err := client.Get(url)
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

	err = json.Unmarshal(apiRes.Data, &folder)
	if err != nil {
		return err
	}

	if id != "" {
		path = filepath.Join(path, folder.Name)
	}
	err = os.MkdirAll(path, os.ModePerm)
	if err != nil {
		return err
	}

	for _, file := range folder.Files {
		if file.Type == "application/vnd.bloom.folder" {
			if err = exportDriveFolder(client, path, file.Id); err != nil {
				return err
			}
		} else {
			if err = exportDriveFile(client, path, file.Name, file.Id); err != nil {
				return err
			}
		}
	}

	return nil
}

func exportDriveFile(client *http.Client, path, name, id string) error {
	var apiRes ApiRes
	var file FileUrl
	url := fmt.Sprintf("https://legacy.bloom.sh/api/drive/v1/files/%s/url", id)

	res, err := client.Get(url)
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

	err = json.Unmarshal(apiRes.Data, &file)
	if err != nil {
		return err
	}

	res2, err := http.Get(file.Url)
	if err != nil {
		return err
	}
	defer res2.Body.Close()

	out, err := os.Create(filepath.Join(path, name))
	if err != nil {
		return err
	}
	defer out.Close()

	_, err = io.Copy(out, res2.Body)

	return err
}
