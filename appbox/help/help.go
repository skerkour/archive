package help

import (
	"fmt"
)

// Run the help sub-command
func Run(args []string) error {
	fmt.Println("appbox is a collection of pretty terminal apps to replace the usual bloated GUI apps. Music, RSS, Calculator...")
	return nil
}
