
#include <vector>
#include <limits>
#include <stdint.h>
#include <climits>
#include <cstdint>
using namespace std;

class Solution {

public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> sum(1 << n);
        for (int i= 1; i < (1 << n); i++) {
            int x = __builtin_ctz(i);
            int y = i - (1 << x);
            sum[i] = sum[y] + jobs[x];
        }

        // dp 表示给前i+1个工人分配工作， 工作的分配情况为j时，完成所有工作的最短时间
        vector<vector<int>> dp(k, vector<int>(1 << n));
        for (int i = 0; i < (1 << n); ++i) {
            dp[0][i] = sum[i];
        }

        for (int i = 1; i < k; i++) {
            // 1 << n 会将n个jobs的所有可能情况都排列出来
            for (int j = 0; j < (1 << n); j++) {
                int val = INT_MAX;
                for (int x = j; x; x = (x - 1) & j) {
                    val = min(val, max(dp[i - 1][j - x], sum[x]));
                }
                dp[i][j] = val;
            }
        }


    }






};










