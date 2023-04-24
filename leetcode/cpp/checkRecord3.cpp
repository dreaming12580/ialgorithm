







#include <iostream>

using namespace std;


class Solution {
private:
	static constexpr int mod = 1e9 + 7;

public:
	int checkRecord(int n) {
		// A 的数量， 结尾连续 L 的数量
		int dp[2][3];
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 1; i <= n; ++i) {
			int dpNew[2][3];   
			memset(dpNew, 0, sizeof(dpNew)); 
			// 以 P 结尾的数量
			for (int j = 0; j <= 1; ++j) {
				for (int k = 0; k <= 2; ++k) {
					dpNew[j][0] = (dpNew[j][0] + dp[j][k]) % mod;
				}
			}
			// 以 A 结尾的数量
			for (int k = 0; k <= 2; ++k) {
				dpNew[1][0] = (dpNew[1][0] + dp[0][k]) % mod;
			}

			// 以 L 结尾的数量
			for (int j = 0; j <= 1; ++j) {
				for (int k = 1; k <= 2; ++k) {
					dpNew[j][k] = (dpNew[j][k] + dp[j][k - 1]) % mod;
				}
			}
			memcpy(dp, dpNew, sizeof(dp));
		}

		int sum = 0;
		for (int j = 0; j <= 1; ++j) {
			for (int k = 0; k <= 2; ++k) {
				sum = (sum + dp[j][k]) % mod;
			}
		}
		return sum;
	}
};




