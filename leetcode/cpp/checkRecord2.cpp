#include <vector>

using namespace std;


class Solution {
private:
	static constexpr int mod = 1e9 + 7;
public:
	int checkRecord(int n) {
		// 长度， A的数量， 结尾连续L的数量
		vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3))); 
		dp[0][0][0] = 1;
		for (int i = 1; i <= n; ++i) {
			// 以 P 结尾的数量
			for (int j = 0; j <= 1; ++j) {
				for (int k = 0; k <= 2; ++k) {
					dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % mod;
				}
			}

			// 以 A 结尾的数量
			for (int k = 0; k <= 2; ++k) {
				dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % mod;
			}

			// 以 L 结尾的数量
			for (int j = 0; j <= 1; ++j) {
				for (int k = 1; k <= 2; ++k) {
					dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % mod;
				}
			}
		}
		int sum = 0;
		for (int j = 0; j <= 1; ++j) {
			for (int k = 0; k <= 2; ++k) {
				sum = (sum + dp[n][j][k]) % mod;
			}
		}
		return sum;
	}
};
















