


class Solution {

public:
	bool canPartition(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) {
			return false;
		}
		int sum = accumulate(nums.begin(), nums.end(), 0);
		int maxn = *max_element(nums.begin(), nums.end());
		if (sum & 1) {
			return false;
		}
		int target = sum / 2;
		if (maxn > target) {
			return false;
		}
		// 创建二维数组dp, 包含 n 行 target + 1 列
		// 其中 dp[i][j] 表示从数组 [0, i] 下标范围内选取若干个正整数 (可以是 0 个)
		vector<vector<int>> dp(n, vector<int>(target + 1, 0));
		for (int i = 0; i < n; ++i) {
			dp[i][0] = true;
		}
		dp[0][nums[0]] = true;
		for (int i = 1; i < n; ++i) {
			int num = nums[i];
			for (int j = 1; j <= target; ++j) {
				if (j >= num) {
					dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
				} else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[n - 1][target];
	}
};











