package calc

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Run the calc sub-command
func Run(args []string) (err error) {
	calc := New()
	if len(args) > 0 {
		input := ""

		for _, arg := range args {
			input += arg
			input += " "
		}
		input = strings.TrimSpace(input)
		if input == "" {
			return
		}
		calc.Load(input)

		//
		// Run it.
		//
		out := calc.Run()

		//
		// Check for errors
		//
		if out.Type == ERROR {
			fmt.Printf("error: %s\n", out.Value.(string))
			return
		}
		if out.Type != NUMBER {
			fmt.Printf("unexpected output %v\n", out)
			return
		}

		//
		// Show the result; int-preferred, if possible
		//
		result := out.Value.(float64)
		if float64(int(result)) == result {
			fmt.Printf("%d\n", int(result))
		} else {
			fmt.Printf("%f\n", result)
		}
		return
	}
	//
	// Repl.
	//
	scanner := bufio.NewScanner(os.Stdin)

	//
	// Show the prompt and read the lines
	//
	fmt.Printf("calc> ")
	for scanner.Scan() {

		//
		// Get the input, and trim it
		//
		input := scanner.Text()
		input = strings.TrimSpace(input)

		//
		// Exit ?
		//
		if strings.HasPrefix(input, "exit") ||
			strings.HasPrefix(input, "quit") {
			return
		}

		//
		// Ignore it, unless it is non-empty
		//
		if input != "" {

			//
			// Load the script
			//
			calc.Load(input)

			//
			// Run it.
			//
			out := calc.Run()

			//
			// Check for errors
			//
			if out.Type == ERROR {
				fmt.Printf("error: %s\n", out.Value.(string))
				return
			}
			if out.Type != NUMBER {
				fmt.Printf("unexpected output %v\n", out)
				return
			}

			//
			// Show the result; int-preferred, if possible
			//
			result := out.Value.(float64)
			if float64(int(result)) == result {
				fmt.Printf("%d\n", int(result))
			} else {
				fmt.Printf("%f\n", result)
			}

		}
		fmt.Printf("calc> ")
	}

	if err := scanner.Err(); err != nil {
		fmt.Println(err)
	}

	return
}
