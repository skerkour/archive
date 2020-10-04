<p align="center">
  <h3 align="center">SANE-go</h3>
  <p align="center">SANE parser for Go</p>
</p>

--------


[![GoDoc](https://godoc.org/gitlab.com/bloom42/libs/sane-go?status.svg)](https://godoc.org/gitlab.com/bloom42/libs/sane-go)
[![GitHub release](https://img.shields.io/github/release/bloom42/sane-go.svg)](https://gitlab.com/bloom42/libs/sane-go/releases/latest)


Spec: [https://gitlab.com/bloom42/sane/sane](https://gitlab.com/bloom42/sane/sane)

Compatible with SANE version: [v1.0.0-beta](https://gitlab.com/bloom42/sane/sane/blob/master/versions/v1.0.0-beta.md)

1. [Installation](#installation)
2. [Library](#library)
3. [Contributing](#contributing)
4. [Licensing](#licensing)
5. [Sponsoring](#sponsoring)
6. [Security](#security)

-------------------


## Installation

```bash
go get -u gitlab.com/bloom42/libs/sane-go/...
```



## Library

```go
package main

import (
	"fmt"

	"gitlab.com/bloom42/libs/sane-go"
)

type D struct {
	A string
}

type C struct {
	A int64 `sane:"a"`
	D []D   `sane:"d"`
}

type S struct {
	A string  `sane:"a"`
	B []int64 `sane:"b"`
	C C       `sane:"c"`
}

func main() {
	str1 := `
a = "a"
b = [1, 2]
c = { a = 1, d = [ { a = "3.3" }, { a = "xxx" } ] }
`
	var s S

	err := sane.Unmarshal([]byte(str1), &s)
	if err != nil {
		panic(err)
	}
	fmt.Printf("%#v\n\n", s)

	b, err := sane.Marshal(s)
	if err != nil {
		panic(err)
	}
	fmt.Print(string(b))
}
```

```bash
go run main.go
main.S{A:"a", B:[]int64{1, 2}, C:main.C{A:1, D:[]main.D{main.D{A:"3.3"}, main.D{A:"xxx"}}}}

a = "a"
b = [
  1,
  2,
]
c = {
  a = 1

  d = [
    {
      A = "3.3"
    },
    {
      A = "xxx"
    },
  ]
}
```


## Contributing

Thank you for your interest in contributing! Please refer to
[https://bloom.sh/contribute](https://bloom.sh/contribute) for guidance.



## Licensing

See `LICENSE.txt` and [https://bloom.sh/licensing](https://bloom.sh/licensing)


## Sponsoring

Bloom is a free and open source project. If you are interested in supporting this project, the core team
and the contributors please visit our
[sponsoring page](https://bloom.sh/become-a-sponsor) ✌️


## Security

If you found a security issue affecting this project, please do not open a public issue and refer to our
[dedicated security page](https://bloom.sh/security) instead. Tahnk you.
