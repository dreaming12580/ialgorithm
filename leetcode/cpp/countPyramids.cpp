
#include <vector>


using namespace std;



class Solution {
public:
	int countPyramids(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> f(m, vector<int>(n));
		int ans = 0;
		// 金字塔
		for (int i = m - 1; i >= 0; --i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 0) {
					f[i][j] = -1;
				} else if (i == m - 1 || j == 0 || j == n - 1) {
					f[i][j] = 0;
				} else {
					f[i][j] = min({f[i + 1][j - 1], f[i + 1][j], f[i + 1][j + 1]}) + 1;
					ans += f[i][j];
				}
			}
		}
		// 倒金字塔
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 0) {
					f[i][j] = -1;
				} else if (i == 0 || j == 0 || j == n - 1) {
					f[i][j] = 0;
				} else {
					f[i][j] = min({f[i - 1][j - 1], f[i - 1][j], f[i - 1][j + 1]}) + 1;
					ans += f[i][j];
				}
			}
		}
		return ans;
	}
};
















