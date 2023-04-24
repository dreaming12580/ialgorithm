
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool> ans(n);

        int m = candiesCount.size();
        vector<long long> pre(m + 1, 0);
        for (int i = 1; i <= m; ++i) {
            pre[i] = pre[i - 1] + candiesCount[i - 1];
        }
        for (int i = 0; i < n; ++i) {
            int f_t = queries[i][0];
            int f_d = queries[i][1];
            int d_c = queries[i][2];

            long long maxn = (long long)(f_d + 1) * d_c;
            long long minn = f_d + 1;
            cout << "minn:" << minn << ", pre:" << pre[f_t] << ", maxn:" << maxn << endl;
            if (pre[f_t] < maxn && maxn <= pre[f_t + 1]) {
                ans[i] = true;
            } else if (pre[f_t] < minn && minn <= pre[f_t + 1]) {
                ans[i] = true;
            } else if (pre[f_t] >= minn && pre[f_t + 1] < maxn) {
                ans[i] = true;
            } else {
                ans[i] = false;
            }
        }
        return ans;

    }
};








