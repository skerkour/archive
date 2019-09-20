package util

import (
	"crypto/rand"
	mathrand "math/rand"
	"time"

	"github.com/google/uuid"
)

const charBytes = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-"

func init() {
	mathrand.Seed(time.Now().UnixNano())
}

func RandomInt(min, max int) int {
	return mathrand.Intn(max-min) + min
}

func RandomString(n uint) string {
	b := make([]byte, n)
	for i := range b {
		b[i] = charBytes[mathrand.Int63()%int64(len(charBytes))]
	}
	return string(b)
}

func RandomBytes(n uint) ([]byte, error) {
	b := make([]byte, n)
	_, err := rand.Read(b)
	// Note that err == nil only if we read len(b) bytes.
	if err != nil {
		return nil, err
	}

	return b, nil
}

func GenerateUUID() (string, error) {
	uuidV4, err := uuid.NewRandom()
	if err != nil {
		return RandomString(35), err
	}

	return uuidV4.String(), nil
}
