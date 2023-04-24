
#include <vector>
#include <string>


using namespace std;

class Solution {

public:
	string largestNumber(vector<int>& cost, int target) {
		// 表示使用前 i 个数位且花费总成本恰好为 j 时的最大位数
		vector<vector<int>> dp(10, vector<int>(target + 1, INT_MIN));
		// 在状态转移时， 记录转移来源
		vector<vector<int>> from(10, vector<int>(target + 1));
		dp[0][0] = 0;
		for (int i = 0; i < 9; ++i) {
			int c = cost[i];
			for (int j = 0; j <= target; ++j) {
				if (j < c) {
					dp[i + 1][j] = dp[i][j];
					from[i + 1][j] = j;
				} else {
					if (dp[i][j] > dp[i + 1][j - c] + 1) {
						dp[i + 1][j] = dp[i][j];
						from[i + 1][j] = j;
					} else {
						dp[i + 1][j] = dp[i + 1][j - c] + 1;
						from[i + 1][j] = j - c;
					}
				}
			}
		}

		if(dp[9][target] < 0) {
			return "0";
		}

		string ans;
		int i = 9, j = target;
		while (i > 0) {
			if (j == from[i][j]) {
				// 如果相等，则第 i 个元素没有被选上
				--i;
			} else {
				// 如果不等， 则第 i 个元素被选上， 并且将 j 更新为 j - c;
				// i 元素不变， 因为可以重复选取多次
				ans += '0' + i;
				j = from[i][j];
			}
		}
		return ans;
	}
};















































