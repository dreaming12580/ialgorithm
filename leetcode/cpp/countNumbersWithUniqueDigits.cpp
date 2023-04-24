
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] * 10 + (9 * pow(10, i - 2) - dp[i - 1]) * (i - 1);
        }
        int sum = 0;
        for (auto& x : dp) {
            sum += x;
        }
        return pow(10, n) - sum;
    }
};


























