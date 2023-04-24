
#include <vector>



using namespace std;


class Solution {

public:
	int shortestPathLength(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<vector<int>> d(n, vector<int>(n, n + 1));
		for (int i = 0; i < n; ++i) {
			for (int j : graph[i]) {
				d[i][j] = 1;
			}
		}

		// 使用 floyd 算法预处理出所有点之间的最短路径长度
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
		// f 表示从任一节点开始到节点 u 为止， 并且经过的关键节点对应的二进制表示
		// 为 mask 时的最短路径长度。
		vector<vector<int>> f(n, vector<int>(1 << n, INT_MAX / 2)); 
		for (int mask = 1; mask < (1 << n); ++mask) {
			// 如果 mask 只包含一个 1， 即 mask 是 2 的幂
			if ((mask & (mask - 1)) == 0) {
				int u = __builtin_ctz(mask);
				f[u][mask] = 0;
			} else {
				for (int u = 0; u < n; ++u) {
					if (mask & (1 << u)) {
						for (int v = 0; v < n; ++v) {
							if ((mask & (1 << v)) && u != v) {
								f[u][mask] = min(f[u][mask], f[v][mask ^ (1 << u)] + d[v][u]);
							}
						}
					}
				}
			}
		}
		int ans = INT_MAX;
		for (int u = 0; u < n; ++u) {
			ans = min(ans, f[u][(1 << n) - 1]);
		}
		return ans;
	}
};



















