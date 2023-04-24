class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), k = costs[0].size();
        vector<int> dp(k);
        int first = INT_MAX, second = INT_MAX;
        for (int j = 0; j < k; j++) {
            dp[j] = costs[0][j];
            if (dp[j] < first) {
                second = first;
                first = dp[j];
            } else if (dp[j] < second) {
                second = dp[j];
            }
        }
        for (int i = 1; i < n; i++) {
            vector<int> dpNew(k);
            int firstNew = INT_MAX, secondNew = INT_MAX;
            for (int j = 0; j < k; j++) {
                int prevMin = dp[j] != first ? first : second;
                dpNew[j] = prevMin + costs[i][j];
                if (dpNew[j] < firstNew) {
                    secondNew = firstNew;
                    firstNew = dpNew[j];
                } else if (dpNew[j] < secondNew) {
                    secondNew = dpNew[j];
                }
            }
            dp = move(dpNew);
            first = firstNew;
            second = secondNew;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
