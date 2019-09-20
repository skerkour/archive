package main

import (
    "database/sql"
    _ "github.com/go-sql-driver/mysql"
    _ "fmt"
    "log"
    "net/http"
    _"github.com/gorilla/mux"
    _ "html"
    "encoding/json"
    "strconv"
    "io/ioutil"
)

var db *sql.DB

type Config struct {
    User        string
    Password    string
    Host        string
    Port        string
    Db          string
    User_token  string
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

    config := readConfig()
    db, err = sql.Open("mysql", config.User+":"+config.Password+"@tcp("+
        config.Host+":"+config.Port+")/"+config.Db)
    if err != nil {
        panic(err.Error())
    }
    defer db.Close()

    router := NewRouter()
    log.Fatal(http.ListenAndServe(":8080", router))
}

type Stock struct {
    Id      uint64
    Date    string
    Value   float64
    Diff    float64
    Dollar  float64
    Btc     float64
}

func GetStocks(w http.ResponseWriter, r *http.Request) {
    var n uint64
    var rows *sql.Rows
    var err error

    nString := r.URL.Query().Get("n")
    if len(nString) > 0 {
        n, _ = strconv.ParseUint(nString, 10, 64)
        rows, err = db.Query("SELECT * FROM test ORDER BY id DESC LIMIT ?", n)
    } else {
        rows, err = db.Query("SELECT * FROM test ORDER BY id DESC")
    }
    if err != nil {
        log.Println("Error : " + err.Error())
    } else {
        defer rows.Close()
    }

    var vals []Stock
    for rows.Next() {
        var id uint64
        var date string
        var value, diff, dollar, btc float64
        if err := rows.Scan(&id, &value, &diff, &date, &dollar, &btc); err != nil {
            log.Fatal(err)
        }
        vals = append(vals, Stock{id, date, value, diff, dollar, btc})
    }
    if err := rows.Err(); err != nil {
        log.Println("Error : "+err.Error())
    }

    w.Header().Set("Content-Type", "application/json; charset=UTF-8")
    w.WriteHeader(http.StatusOK)
    json.NewEncoder(w).Encode(vals)
}
