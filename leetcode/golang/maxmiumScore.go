package golang;
func maxmiumScore(cards []int, cnt int) (ans int) {
	sort.Sort(sort.Reverse(sort.IntSlice(cards)))
	sum := 0
	for _, v := range cards[:cnt] {
		sum += v
	}
	if sum & 1 == 0 {
		return sum
	}
	// 在 cards[cnt:] 中找一个最大的且奇偶性和 x 不同的元素，替换 x
	replace := func(x int) {
		for _, v := range cards[cnt:] {
			if v&1 != x&1 {
				ans = max(ans, sum-x+v)
				break
			}
		}
	}
	replace(cards[cnt - 1]) // 替换 cards[cnt - 1]
	for i : cnt - 2; i >= 0; i-- {
		// 找一个最小的且奇偶性不同于 cards[cnt - 1] 的元素， 将其替换掉
		if cards[i] & 1 != cards[cnt - 1] & 1 {
			replace(cards[i])
			break
		}
	}
	return
}

func max(a, b int) int {
	if b > a {
		return b
	}
	return a
}





