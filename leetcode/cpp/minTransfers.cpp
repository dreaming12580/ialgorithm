
class Solution {
public:

  int minTransfers(vector<vector<int>>& transactions) {
    const int n = 12, m = 1 << n;
    int cnt[n] = {};
    for (auto& d : transactions) {
      cnt[d[0]] -= d[2];
      cnt[d[0]] += d[1];
    }
    int f[m];
    f[0] = 0;
    for (int i = 1; i < m; ++i) {
      int sum = 0;
      for (int j = 0; j < n; ++j) {
        if (i >> j & 1) {
          sum += cnt[j];
        }
      }
      if (sum) {
        // 防止溢出
        f[i] = INT_MAX / 2;
      } else {
        f[i] = __builtin_popcount(i) - 1;
        for (int j = (i - 1) & i; j > 0; j = (j - 1) & i) {
          f[i] = min(f[i], f[j] + f[i ^ j]);
        }
      }
    }
    return f[m - 1];
  }
};


















