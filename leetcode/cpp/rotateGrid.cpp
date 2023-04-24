
#include <vector>

using namespace std;

class Solution {

public:
	vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
		int m = grid.size();
		int n = grid[0].size();
		// 层数
		int nlayer = min(m / 2, n / 2);
		// 从左上角起逆时针枚举每一层
		for (int layer = 0; layer < nlayer; ++layer) {
			// 每个元素的行下标， 列下标与数值
			vector<int> r, c, val;
			// 左
			for (int i = layer; i < m - layer - 1; ++i) {
				r.push_back(i);
				c.push_back(layer);
				val.push_back(grid[i][layer]);
			}
			// 下
			for (int j = layer; j < n - layer - 1; ++j) {
				r.push_back(m - layer - 1);
				c.push_back(j);
				val.push_back(grid[m - layer - 1][j]);
			}
			// 右
			for (int i = m - layer - 1; i > layer; --i) {
				r.push_back(i);
				c.push_back(n - layer - 1);
				val.push_back(grid[i][n - layer - 1]);
			}
			// 上
			for (int j = n - layer - 1; j > layer; --j) {
				r.push_back(layer);
				c.push_back(j);
				val.push_back(grid[layer][j]);
			}
			// 每一层的元素总数
			int total = val.size();
			// 等效轮转次数
			int kk = k % total;
			// 找到每个下标对应的轮转后的取值
			for (int i = 0; i < total; ++i) {
				// 轮转后取值对应的下标
				int idx = (i + total - kk) % total;
				grid[r[i]][c[i]] = val[idx];
			}


		}
		return grid;
	}
};
























