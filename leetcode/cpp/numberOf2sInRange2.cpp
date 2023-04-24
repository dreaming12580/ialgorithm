
#include <algorithm>

#include <vector>


using namespace std;


class Solution {
public:
	int numberOf2sInRange(int n) {
		if (n < 2) {
			return 0;
		}
		int digit = log10(n) + 1;
		vector<vector<long>> dp(digit + 1, vector<long>(2, 0);)
		dp[1][0] = n % 10 >= 2 ? 1 : 0;
		dp[1][1] = 1;
		for (int i = 2; i <= digit; ++i) {
			int k = (int)(n / pow(10, i - 1)) % 10;
			dp[i][0] = k * dp[i - 1][1] + dp[i - 1][0];
			if (k == 2) {
				dp[i][0] += n % (int)pow(10, i - 1) + 1;
			} else if (k > 2) {
				dp[i][0] += pow(10, i - 1);
			}
			// 新一位的10种选择 * 之前含 2 总个数 + 最高位为 2 的次数
			dp[i][1] = 10 * dp[i - 1][1] + pow(10, i - 1);
		}
		return dp[digit][0];
	}
};
















