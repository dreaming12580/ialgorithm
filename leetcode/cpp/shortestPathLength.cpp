
#include <vector>
#include <queue>


using namespace std;




class Solution {
public:	
	int shortestPathLength(vector<vector<int>>& graph) {
		int n = graph.size();
		/**
		 *  u 表示当前位于的节点编号
		 *  mask 是一个长度为 n 的二进制数，表示每一个节点是否经过。如果 mask 的第 i 位是 1，则表示节点 i 已经过，否则表示节点 i 未经过；
		 *  dist 表示到当前节点为止经过的路径长度
		 */
		queue<tuple<int, int, int>> q;
		vector<vector<int>> seen(n, vector<int>(1 << n));
		for (int i = 0; i < n; ++i) {
			q.emplace(i, 1 << i, 0);
			seen[i][1 << i] = true;
		}

		int ans = 0;
		while (!q.empty()) {
			auto [u, mask, dist] = q.front();
			q.pop();
			if (mask == (1 << n) - 1) {
				ans = dist;
				break;
			}
			// 搜索相邻的节点
			for (int v : graph[u]) {
				// 将 mask 的第 v 位置为 1
				int mask_v = mask | (1 << v);
				if (!seen[v][mask_v]) {
					q.emplace(v, mask_v, dist + 1);   
					seen[v][mask_v] = true;
				}
			}
		}
		return ans;
	}
};



















