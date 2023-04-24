

#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int diff = sum - target;
        if (diff < 0 || diff % 2 != 0) {
            return 0;
        }
        int neg = diff / 2;
        vector<int> dp(neg + 1);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            for (int j = neg; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }
        return dp[neg];
    }
};

















