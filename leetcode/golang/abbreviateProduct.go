package golang

import (
	"fmt"
	"math/big"
)

func abbreviateProduct(left, right int) string {
	s := new(big.Int).MulRange(int64(left), int64(right)).String()
	c := 0
	for s[len(s)-1-c] == '0' {
		c++
	}
	s = s[:len(s)-c]
	if len(s) > 10 {
		return fmt.Sprintf("%s...%se%d", s[:5], s[len(s)-5:], c)
	}
	return fmt.Sprintf("%se%d", s, c)
}
