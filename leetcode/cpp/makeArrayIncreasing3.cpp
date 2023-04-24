
constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        /* 右侧哨兵 inf */
        arr1.push_back(INF); 
        /* 左侧哨兵 -1 */
        arr1.insert(arr1.begin(), -1); 
        int n = arr1.size();
        int m = arr2.size();

        vector<int> dp(n, INF);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            /* arr1[i] 左侧的元素不进行替换 */
            if (arr1[i - 1] < arr1[i]) {
                dp[i] = min(dp[i], dp[i - 1]);
            }
            /* 固定替换元素的右侧终点 */
            int k = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
            /* 枚举从 i 左侧连续替换元素的个数 */
            for (int j = 1; j <= min(i - 1, k); ++j) {
                /* 替换的连续 j 个元素的左侧起点需满足大于 arr1[i - j - 1] */ 
                if (arr1[i - j - 1] < arr2[k - j]) {
                    dp[i] = min(dp[i], dp[i - j - 1] + j);
                }
            }
        }
        return dp[n - 1] == INF ? -1 : dp[n - 1];
    }
};









