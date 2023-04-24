

#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:

	bool stoneGame(vector<int>& piles) {
		int len = piles.size();
		auto dp = vector<vector<int>>(len, vector<int>(len));
		for (int i = 0; i < len; ++i) {
			dp[i][i] = piles[i];
		}
		for (int i = len - 2; i >= 0; --i) {
			for (int j = i + 1; j < len; ++j) {
				dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
			}
		}
		return dp[0][len -1];
	}




}






