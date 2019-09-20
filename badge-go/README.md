## Badge

[![GoDoc](https://godoc.org/github.com/bloom42/badge-go?status.svg)](https://godoc.org/github.com/bloom42/badge-go)
[![GitHub release](https://img.shields.io/github/release/bloom42/badge-go.svg)](https://github.com/bloom42/badge-go/releases)

badge-go is a library to render SVG shield badges.

1. [Usage](#Usage)
2. [Examples](#examples)
3. [Contributing](#contributing)
4. [License](#license)

-------------------

## Usage

```go
package main

import (
	"fmt"
	"os"

	"github.com/bloom42/badge-go"
)

func main() {
	err := badge.Render("godoc", "reference", "#5272B4", os.Stdout)
	if err != nil {
		panic(err)
	}

	badge, err := badge.RenderBytes("godoc", "reference", "#5272B4")
	if err != nil {
		panic(err)
	}
	fmt.Printf("%s", badge)
}

```


## Examples

See the [examples](https://github.com/bloom42/astro-go/tree/master/examples) folder.


## Contributing

See [https://opensource.bloom.sh/contributing](https://opensource.bloom.sh/contributing)


## License

See `LICENSE.txt` and [https://opensource.bloom.sh/licensing](https://opensource.bloom.sh/licensing)
