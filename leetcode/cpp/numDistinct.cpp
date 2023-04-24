#include <string>
#include <vector>
using namespace std;




class Solution {

public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        if (m < n) {
            return 0;
        }
        vector<vector<long>> dp(m+1, vector<long>(n+1));
        for (int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }
        for (int i = m - 1; i >= 0; i--) {
            char sc = s[i];
            for (int j = n - 1; j >= 0; j--) {
                char tc = t[j];
                if (sc == tc) {
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                } else {
                    dp[i][j] = dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};



