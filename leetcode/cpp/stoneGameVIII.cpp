
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pre;
        partial_sum(stones.begin(), stones.end(), back_inserter(pre));
        vector<int> f(n);
        f[n - 1] = pre[n - 1];
        for (int i = n - 2; i >= 1; --i) {
            // 不选择第i个， 与选择第i个
            f[i] = max(f[i + 1], pre[i] - f[i + 1]);
        }
        return f[1];
    }
};















