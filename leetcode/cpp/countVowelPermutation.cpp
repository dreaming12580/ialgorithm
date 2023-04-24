#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
	long long mod = 1e9 + 7;
public:
	int countVowelPermutation(int n) {
		vector<long long> dp(5, 1);
		vector<long long> ndp(5);
		for (int i = 2; i <= n; ++i) {
			/* a前面可以为 e, u, i */
			ndp[0] = (dp[1] + dp[2] + dp[4]) % mod;
			/* e前面可以为 a, i */
			ndp[1] = (dp[0] + dp[2]) % mod;
			/* i前面可以为 e, o */
			ndp[2] = (dp[1] + dp[3]) % mod;
			/* o前面可以为 i */
			ndp[3] = dp[2];
			/* u前面可以为 i, o */
			ndp[4] = (dp[2] + dp[3]) % mod;
			dp = ndp;
		}
		return accumulate(dp.begin(), dp.end(), 0LL) % mod;
	}
};













