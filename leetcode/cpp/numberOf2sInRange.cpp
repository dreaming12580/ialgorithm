
#include <vector>
#include <cmath>


using namespace std;


class Solution {
public:

    int numberOf2sInRange(int n) {
        if (n == 0) {
            return 0;
        }
        int bits = log10(n) + 1;
        vector<vector<int>> dp(bits + 1, vector<int>(2));
        // dp[i][0] = numberOf2sInRange(n % pow(10, i))
        // 保存0 ~ n的1 到 i位组成的数包含2的个数
        // dp[i][1] = numberOf2sInRange(99..9)
        // 保存 i 位均为 9 组成的数包含2的个数
        dp[1][0] = n % 10 >= 2 ? 1 : 0;
        dp[1][1] = 1;
        
        for (int i = 2; i <= bits; ++i) {
            int t = pow(10, i - 1);
            int k = n / t % 10;
            dp[i][0] = k * dp[i - 1][1] + dp[i - 1][0];
            if (k == 2) {
                dp[i][0] += n % t + 1;
            } else if (k > 2) {
                dp[i][0] += t;
            }
            // 计算1到i位均为9的值包含2的个数
            if (i == bits) {
                dp[i][1] = 10 * dp[i - 1][1] + t;
            }
        }
        return dp[bits][0];
    }
};
















