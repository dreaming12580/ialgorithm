package golan

func check(c [3]int) bool {
	if c[1] == 0 {
		return false
	}
	c[1]--                               // 开头为 1
	turn := 1 + min(c[1], c[2])*2 + c[0] // 计算回合数
	if c[1] > c[2] {
		turn++
		c[1]--
	}
	return turn%2 == 1 && c[1] != c[2] // 回合数为奇数，且还有剩余石子
}

func stoneGameIX(stones []int) bool {
	c := [3]int{}
	for _, v := range stones {
		c[v%3]++
	}
	return check(c) || check([3]int{c[0], c[2], c[1]}) // 枚举第一回合移除的是 1 还是 2
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
