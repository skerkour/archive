package main

import (
    "net/http"
    "encoding/json"
    "log"
    "strconv"
    "time"
)

type Resp struct {
    Ok  bool
}

func kindToType(kind string) (int64) {
    switch kind {
        case "buy":
            return 0
        case "sell":
            return 1
        default:
            return 0
    }
}

func PostOrders(w http.ResponseWriter, r *http.Request) {
    good := false
    kindStr := r.FormValue("kind")
    amountStr := r.FormValue("btc_amount")
    token := r.FormValue("user_token")
    date := time.Now().UTC().Format(time.RFC3339)
    date = date[:len(date)-1] 
    if len(kindStr) > 0 && len(amountStr) > 0 && len(token) > 0 {
        typeInt := kindToType(kindStr)
        amount, _ := strconv.ParseFloat(amountStr, 64)
        _, err := db.Exec("INSERT INTO orders (type, amount, token, done, date) VALUES (?, ?, ?, FALSE, ?)",
            typeInt, amount, token, date)
        if err != nil {
            log.Println("ERROR :" +err.Error())
        } else {
            good = true
        }

    }

    resp := Resp{good}
    w.Header().Set("Content-Type", "application/json; charset=UTF-8")
    w.WriteHeader(http.StatusOK)
    json.NewEncoder(w).Encode(resp)
}
