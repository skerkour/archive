<p align="center">
  <h3 align="center">DEnv</h3>
  <p align="center">Default ENVironment variables for Go</p>
</p>

--------

[![GoDoc](https://godoc.org/github.com/bloom42/denv-go?status.svg)](https://godoc.org/github.com/bloom42/denv-go)
[![GitHub release](https://img.shields.io/github/release/bloom42/denv-go.svg)](https://github.com/bloom42/denv-go/releases/latest)

1. [Usage](#usage)
2. [License](#license)

-------------------

## Usage

```go
package main

import (
	"fmt"
	"os"

	"github.com/bloom42/denv-go"
)

func main() {
	os.Setenv("FIRST_NAME", "Sysy")
	denv.Init(denv.Env{
		"FIRST_NAME": "Sylvain",
		"LAST_NAME":  "Kerkour",
	})

	fmt.Println("FIRST_NAME:", os.Getenv("FIRST_NAME"))
	fmt.Println("LAST_NAME:", os.Getenv("LAST_NAME"))
}

// FIRST_NAME: Sysy
// LAST_NAME: Kerkour
```

## License

See `LICENSE.txt` and [https://opensource.bloom.sh/licensing](https://opensource.bloom.sh/licensing)
