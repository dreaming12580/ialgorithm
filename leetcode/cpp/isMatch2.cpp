
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

	bool isMatch(string s, string p) {
		int m = s.size();
		int n = p.size();
		// 前 i 个字符的s 和 前 j 个字符的p 是否匹配上
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));
		dp[0][0] = true;
		for (int i = 1; i <= n; ++i) {
			if (p[i - 1] == '*') {
				dp[0][i] = true;
			} else {
				break;
			}
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (p[j - 1] == '*') {
					dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
				} else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
			}
		}
		return dp[m][n];
	}












};




















