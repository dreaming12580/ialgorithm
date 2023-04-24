#include <vector>
#include <climits>

using namespace std; 


class Solution {
public:
	int minimizeTheDifference(vector<vector<int>>& mat, int target) {
		int m = mat.size(), n = mat[0].size();
		vector<int> f(target, 0);
		// 什么都不选时和为 0
		f[0] = true;
		// 最大的大于等于 target 的和
		int large = INT_MAX;
		for (int i = 0; i < m; ++i) {
			vector<int> g(target);
			int next_large = INT_MAX;
			for (int x: mat[i]) {
				for (int j = 0; j < target; ++j) {
					if (f[j]) {
						if (j + x >= target) {
							next_large = min(next_large, j + x);
						} else {
							g[j + x] = true;
						}
					}
				}
				if (large != INT_MAX) {
					next_large = min(next_large, large + x);
				}
			}
			f = move(g);
			large = next_large;
		}
		int ans = abs(large - target);
		for (int i = target - 1; i >= 0; --i) {
			if (f[i]) {
				ans = min(ans, target - i);
				break;
			}
		}
		return ans;
	}




};















