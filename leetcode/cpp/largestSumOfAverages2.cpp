

class Solution {

public:
	double largestSumOfAverages(vector<int>& nums, int k) {
		int n = nums.size();
		vector<double> prefix(n + 1);
		for (int i = 0; i < n; ++i) {
			prefix[i + 1] = prefix[i] + nums[i];
		}

		// dp[i][j] 表示 nums在区间[0, i - 1]被切分成 j 个子数组的最大平均值和， 显然i >= j。
		vector<vector<double>> dp(n + 1, vector<double>(k + 1));
		for (int i = 1; i <= n; ++i) {
			dp[i][1] = prefix[i] / i;
		}
		for (int j = 2; j <= k; ++j) {
			for (int i = j; i <= n; ++i) {
				for (int x = j - 1; x < i; ++x) {
					dp[i][j] = max(dp[i][j], dp[x][j - 1] + (prefix[i] - prefix[x]) / (i - x));
				}
			}
		}
		return dp[n][k];
	}
};

