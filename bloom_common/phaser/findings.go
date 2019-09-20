package phaser

import (
	"github.com/bloom42/common/phaser/findings"
)

type Findings struct {
	Ports []findings.Port `json:"ports"`
	CNAME *string         `json:"cname"`
}
