package main

import (
	"fmt"
	"log"
	"net/http"
	"os"
	"strings"
)

func usage(name string) {
	fmt.Println("Usage :", name, "<expression>")
}

func main() {
	if len(os.Args) != 2 {
		usage(os.Args[0])
		os.Exit(-42)
	}

	if os.Args[1] == "-w" {
		fmt.Println("The server is now listening on port 4242")
		http.HandleFunc("/", servePage)
		http.Handle("/assets", http.FileServer(http.Dir("./assets/")))
		if err := http.ListenAndServe(":4242", nil); err != nil {
			log.Fatal("Error starting ther server :", err)
		}

	} else {
		var lexer Lexer
		tokens := lexer.Lex(strings.ToLower(os.Args[1]))
		for _, token := range tokens {
			fmt.Println(token)
			if token.Type == ERROR {
				fmt.Println(lexer.Error())
			}
		}
	}
}
