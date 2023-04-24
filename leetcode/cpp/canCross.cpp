

#include <vector>


using namespace std;



class Solution {

public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = true;
        for (int i = 1; i < n; ++i) {
            // 当第i个石子与第i-1个石子距离超过i时， 必定跳不过去
            if (stones[i] - stones[i - 1] > i) {
                return false;
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int k = stones[i] - stones[j];
                // 在第j个石子上，我们至多跳出j+1的距离
                if (k > j + 1) {
                    break;
                }
                dp[i][k] = dp[j][k-1] || dp[j][k] || dp[j][k+1];
                if (i == n - 1 && dp[i][k]) {
                    return true;
                }
            }
        }
        return false;
    }
};











