
#include <vector>


using namespace std;



class Solution {

public:
	int numWays(int n, vector<vector<int>>& relation, int k) {
		vector<int> dp(n);
		dp[0] = 1;
		for (int i = 0; i < k; ++i) {
			vector<int> next(n);
			for (auto& edge : relation) {
				int src = edge[0], dst = edge[1];
				next[dst] += dp[src];
			}
			dp = next;
		}
		return dp[n - 1];
	}

};



















