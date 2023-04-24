#include <iostream>
#include <vector>
#include <limits>
#include <stdint.h>

using namespace std;

class Solution {

public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> f(n, vector<int>(n, true));
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = (s[i] == s[j]) && f[i+1][j-1];
            }
        }

        // 表示从位置0到位置i的最小切割次数
        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            if (f[0][i]) {
                dp[i] = 0;
            } else {
                for (int j = 0; j < i; ++j) {
                    if (f[j+1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        return dp[n-1];
    }
};










