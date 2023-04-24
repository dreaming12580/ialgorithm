
class Solution {

public:

	int numDupDigitsAtMostN(int n) {
		auto s = to_string(n);
		int m = s.length(), dp[m][1 << 10];
		// -1 表示没有计算过
		memset(dp, -1, sizeof(dp));
		function<int(int, int, bool, bool)> f = [&](int i, int mask, bool is_limit, bool is_num) -> int {
			if (i == m) {
				// is_num 为 true 表示得到了一个合法数字
				return is_num;
			}
			if (!is_limit && is_num && dp[i][mask] != -1) {
				return dp[i][mask];
			}
			int res = 0;
			// 可以跳过当前数位
			if (!is_num) {
				res = f(i + 1, mask, false, false);
			}
			// 如果前面填的数字和 n 的一样， 那么这一位至多填 s[i] (否则就超过 n 啦)
			int up = is_limit ? s[i] - '0' : 9;
			// 枚举要填入的数字 d
			for (int d = 1 - is_num; d <= up; ++d) {
				//  d 不在 mask 中
				if ((mask >> d & 1) == 0) {
					res += f(i + 1, mask | (1 << d), is_limit && d == up, true);
				}
			}
			if (!is_limit && is_num) {
				dp[i][mask] = res;
			}
			return res;
		};
		return n - f(0, 0, true, false);
	}
};



















