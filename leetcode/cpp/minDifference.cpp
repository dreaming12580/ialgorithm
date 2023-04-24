#include <vector>
#include <array>

#include <algorithm>

using namespace std;

class Solution {
private:
	// 元素 c 的最大值
	static constexpr int C = 100;

public:
	vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
		int n = nums.size();
		// 前缀和
		vector<array<int, C + 1>> pre(n + 1);
		fill(pre[0].begin(), pre[0].end(), 0);
		for (int i = 0; i < nums.size(); ++i) {
			copy_n(pre[i].begin(), C + 1, pre[i + 1].begin());
			++pre[i + 1][nums[i]];
		}

		int q = queries.size();
		vector<int> ans;
		for (int i = 0; i < q; ++i) {
			int left = queries[i][0], right = queries[i][1];
			// last 记录上一个出现的元素
			// best 记录相邻两个元素差值的最小值
			int last = 0, best = INT_MAX;
			for (int j = 1; j <= C; ++j) {
				if (pre[left][j] != pre[right + 1][j]) {
					if (last) {
						best = min(best, j - last);
					}
					last = j;
				}
			}
			if (best == INT_MAX) {
				best = -1;
			}
			ans.push_back(best);
		}
		return ans;
	}
};





















