

constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
  int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    sort(arr2.begin(), arr2.end());
    arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
    // 右侧哨兵 inf
    arr1.push_back(INF);
    // 左侧哨兵 -1
    arr1.insert(arr1.begin(), -1);
    int n = arr1.size();
    int m = arr2.size();

    // dp[i] 为使数组 arr1[i] 的前 i 项递增， 且保留 arr1[i] 的情况下的最小替换次数
    vector<int> dp(n, INF);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
      // arr1[i] 左侧的元素不进行替换
      if (arr1[i - 1] < arr1[i]) {
        dp[i] = min(dp[i], dp[i - 1]);
      }
      // 替换 arr1[i] 左侧的连续 j 个元素
      for (int j = 1; j < i; ++j) {
        // arr2 的最优替换的起点为大于 arr1[i - j - 1] 的最小元素
        int k = upper_bound(arr2.begin(), arr2.end(), arr1[i - j - 1]) - arr2.begin();
        // arr2 的最优替换的终点必须满足小于 arr1[i]
        if (k + j - 1 < m && arr2[k + j - 1] < arr1[i]) {
          dp[i] = min(dp[i], dp[i - j - 1] + j);
        }
      }
    }
    return dp[n - 1] == INF ? -1 : dp[n - 1];
  }
};















