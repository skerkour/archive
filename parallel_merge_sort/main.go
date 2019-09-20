package main

import (
    "math/rand"
    "time"
    "sort"
    "fmt"
)

func main() () {
    const vSize int64 = 50000000
    v := make([]float64, vSize, vSize)

    r := rand.New(rand.NewSource(time.Now().UnixNano()))

    for i, _ := range v {
        v[i] = r.Float64()
    }
    t0 := time.Now()
    sort.Float64s(v)
    t1 := time.Now()
    fmt.Printf("The call took %v to run.\n", t1.Sub(t0))
}
