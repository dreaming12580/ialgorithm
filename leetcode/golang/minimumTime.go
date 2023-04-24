package golang

func minimumTime(n int, relations [][]int, time []int) (ans int) {
	// 是 节点 v 的出度
	g := make([][]int, n)
	// 是 节点 w 的入度
	deg := make([]int, n)

	for _, e := range relations {
		v, w := e[0]-1, e[1]-1
		g[v] = append(g[v], w)
		deg[w]++
	}
	// 维持入度为 0 的节点
	q := []int{}
	for i, d := range deg {
		if d == 0 {
			q = append(q, i)
		}
	}
	// 当没有遍历到节点 v 的时候， 保存其他节点到节点 v 需要的最大时间
	// 当遍历到节点 v 的时候， 保存其他节点到节点 v 需要的最大时间 加上 节点 v 消耗的时间
	f := make([]int, n)
	for len(q) > 0 {
		v := q[0]
		q = q[1:]
		f[v] += time[v]
		ans = max(ans, f[v])
		for _, w := range g[v] {
			f[w] = max(f[w], f[v])
			if deg[w]--; deg[w] == 0 {
				q = append(q, w)
			}
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
