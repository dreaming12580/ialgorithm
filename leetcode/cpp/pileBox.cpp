#include <vector>
#include <algorithm>


using namespace std;

class Solution {

public:
    int pileBox(vector<vector<int>>& box) {
        sort(box.begin(), box.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        vector<int> dp(box.size(), 0);
        // dp[i] 表示以第i个箱子为结尾的上升子序列的最大总高度
        dp[0] = box[0][2];
        int ans = dp[0];
        for (int i = 1; i < box.size(); ++i) {
            int maxn = 0; //必须初始化为0
            for (int j = 0; j < i; ++j) {
                if (box[j][0] < box[i][0] &&
                        box[j][1] < box[i][1] &&
                        box[j][2] < box[i][2]) {
                    maxn = max(maxn, dp[j]);
                }
            }
            dp[i] = maxn + box[i][2];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};



