package main

import (
	"bufio"
	"bytes"
	"encoding/json"
	"errors"
	"fmt"
	"io/ioutil"
	"net/http"
	"os"
	"strings"

	"golang.org/x/crypto/ssh/terminal"
)

type SignInReq struct {
	Username string `json:"username"`
	Password string `json:"password"`
}

type SignInRes struct {
	Id    string `json:"id"`
	Token string `json:"token"`
}

func AskCredentials() (string, string, error) {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Username: ")
	username, err := reader.ReadString('\n')
	if err != nil {
		return "", "", err
	}

	fmt.Print("Password: ")
	passwordBytes, err := terminal.ReadPassword(int(os.Stdin.Fd()))
	if err != nil {
		return "", "", err
	}

	password := string(passwordBytes)
	fmt.Print("\n")

	return strings.ToLower(strings.TrimSpace(username)), strings.TrimSpace(password), nil
}

func Authenticate(client *http.Client, username, password string) (string, error) {
	ret := ""
	req := SignInReq{
		Username: username,
		Password: password,
	}
	var apiRes ApiRes
	var signInRes SignInRes

	reqJson, err := json.Marshal(req)
	if err != nil {
		return ret, err
	}

	res, err := client.Post("https://legacy.bloom.sh/api/myaccount/v1/sign-in", "application/json", bytes.NewBuffer(reqJson))
	if err != nil {
		return ret, err
	}
	defer res.Body.Close()

	resBody, err := ioutil.ReadAll(res.Body)
	if err != nil {
		return ret, err
	}

	err = json.Unmarshal(resBody, &apiRes)
	if err != nil {
		return ret, err
	}

	if apiRes.Error != nil {
		return ret, errors.New(apiRes.Error.Message)
	}

	err = json.Unmarshal(apiRes.Data, &signInRes)
	if err != nil {
		return ret, err
	}

	return signInRes.Token, nil
}

type AddHeaderTransport struct {
	Transport http.RoundTripper
	Token     string
}

func (adt *AddHeaderTransport) RoundTrip(req *http.Request) (*http.Response, error) {
	req.Header.Add("Authorization", fmt.Sprintf("Basic %s", adt.Token))
	return adt.Transport.RoundTrip(req)
}

func AuthTransport(transport http.RoundTripper, token string) *AddHeaderTransport {
	if transport == nil {
		transport = http.DefaultTransport
	}
	return &AddHeaderTransport{
		Transport: transport,
		Token:     token,
	}
}
