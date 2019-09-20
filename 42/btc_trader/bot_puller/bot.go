package main

import (
    "fmt"
    "time"
    "database/sql"
    _ "github.com/go-sql-driver/mysql"
    "net/http"
    "io/ioutil"
    "encoding/json"
    "strconv"
    "log"
    "strings"
    "net/url"
)

type Config struct {
    User        string
    Password    string
    Host        string
    Port        string
    Db          string
    User_token  string
}

type Fees struct {
    Static      string
    Varaible    string
}

type Transaction struct {
    Id          int64
    UserId      int64
    Kind        string
    Created_at   string
    Updated_at   string
    Btc_amount   string
    Current_value    int64
    Fees            string
}

type Stocks struct {
    Values      []Value
    Current     string
    Diff        string
    Money_dollar string
    Money_btc    string
    Fees        Fees
    Transactions    []Transaction
}

type Value struct {
    Id          int64
    Value       float64
    CreatedAt   string
    UpdatedAt   string
}

var db *sql.DB
var config Config

func doRead(ticker *time.Ticker) {
    for t := range ticker.C {
        go func() {
            resp, err := http.Get("http://bitcoin.42.fr/value.json?user_token="+config.User_token)
            if err != nil {
                log.Println("ERROR :" +err.Error())
                return
            }
            dataJson, _ := ioutil.ReadAll(resp.Body)
            resp.Body.Close()

            stocks := Stocks{}
            json.Unmarshal(dataJson, &stocks)
            current, _ := strconv.ParseFloat(stocks.Current, 64)
            diff, _ := strconv.ParseFloat(stocks.Diff, 64)
            dollar, _ := strconv.ParseFloat(stocks.Money_dollar, 64)
            btc, _ := strconv.ParseFloat(stocks.Money_btc, 64)
            date := time.Now().UTC().Format(time.RFC3339)
            date = date[:len(date)-1]
            fmt.Println(current, diff, date, dollar, btc)
            _ = t
            go func () {
                _, err := db.Exec("INSERT INTO test (value, diff, date, money_dollar, money_btc) VALUES (?, ?, ?, ?, ?)",
                    current, diff, date, dollar, btc)
                if err != nil {
                    log.Println("ERROR :" +err.Error())
                }
            }()
        }()
    }
}

func typeToKind(typee int64) (string) {
    switch typee {
        case 0:
            return "buy"
        case 1:
            return "sell"
        default:
            return "sell"
    }
}

func doOrder(token, kind string, amount float64) {
    amountInt := strconv.Itoa(int(amount))
    hc := http.Client{}

    form := url.Values{}
    form.Add("user_token", token)
    form.Add("btc_amount", amountInt)
    form.Add("kind", kind)

    req, _ := http.NewRequest("POST", "http://bitcoin.42.fr/exchange", strings.NewReader(form.Encode()))
    req.PostForm = form
    req.Header.Add("Content-Type", "application/x-www-form-urlencoded")

    if _, err := hc.Do(req); err != nil {
        log.Println("Error : " + err.Error())
    }
}

func doOrders(ticker *time.Ticker) {
    for t := range ticker.C {
        _ = t
        go func () {
            rows, err := db.Query("SELECT * FROM orders WHERE done = FALSE")
            if err != nil {
                log.Println("Error : " + err.Error())
            } else {
                defer rows.Close()

                // get the orders
                for rows.Next() {
                        // execute the order
                        var id uint64
                        var typee int64
                        var kind, token, date string
                        var amount float64
                        var done bool
                        if err := rows.Scan(&id, &typee, &amount, &token, &done, &date); err != nil {
                            log.Println("Error : "+err.Error())
                        }
                        kind = typeToKind(typee)
                        _ = kind
                        doOrder(token, kind, amount)
                        // set the order as done
                        _, err := db.Exec("UPDATE orders SET done = TRUE WHERE id = ?", id)
                        if err != nil {
                            log.Println("Error : "+err.Error())
                        }
                }
                if err := rows.Err(); err != nil {
                    log.Println("Error : "+err.Error())
                }
            }
        }()
    }
}

func readConfig() (ret Config) {
    configJson, err := ioutil.ReadFile("../config.json")
    if err != nil {
        panic(err)
    }
    json.Unmarshal(configJson, &ret)
    return
}

func main() {
    var err error

    config = readConfig()
    db, err = sql.Open("mysql", config.User+":"+config.Password+"@tcp("+
        config.Host+":"+config.Port+")/"+config.Db)
    if err != nil {
        panic(err.Error())
    }
    defer db.Close()

    ticker := time.NewTicker(time.Second)
    ticker2 := time.NewTicker(time.Millisecond * 420)
    go doRead(ticker)
    go doOrders(ticker2)
    select{}
}
