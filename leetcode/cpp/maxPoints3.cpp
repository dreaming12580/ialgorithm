


class Solution {
	const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
	vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries) {
		int m = grid.size(), n = grid[0].size(), mn = m * n;

		// 并查集模板
		int fa[mn], size[mn];
		iota(fa, fa + mn, 0);
		fill(size, size + mn, 1);
		function<int(int)> find = [&](int x) -> int {
			return fa[x] == x ? x : fa[x] = find(fa[x]);
		};
		auto merge = [&](int from, int to) {
			from = find(from);
			to = find(to);
			if (from != to) {
				fa[from] = to;
				size[to] += size[from];
			}
		};

		// 矩阵元素从小到大排序，方便离线
		array<int, 3> a[mn];
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				a[i * n + j] = {grid[i][j], i, j};
			}
		}
		sort(a, a + mn);

		// 查询的下标按照查询值从小到大排序， 方便离线
		int k = queries.size(), id[k];
		iota(id, id + k, 0);
		sort(id, id + k, [&](int i, int j) {
			return queries[i] < queries[j];
		});

		vector<int> ans(k);
		int j = 0;
		for (int i : id) {
			int q = queries[i];
			for (; j < mn && a[j][0] < q; ++j) {
				int x = a[j][1], y = a[j][2];
				// 枚举周围四个格子，值小于 q 才可以合并
				for (auto &d : dirs) {
					int x2 = x + d[0], y2 = y + d[1];
					if (0 <= x2 && x2 < m && 0 <= y2 && y2 < n && grid[x2][y2] < q) {
						// 把坐标压缩成一维的编号
						merge(x * n + y, x2 * n + y2);
					}
				}
			}
			if (grid[0][0] < q) {
				// 左上角的连通块的大小
				ans[i] = size[find(0)];
			}
		}
		return ans;
	}
}; 























