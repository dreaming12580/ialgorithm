#include <vector>
#include <stdint.h>


using namespace std;


class Solution {
public:
    int maxSubSubmatrix(vector<vector<int>> &matrix, int k) {
        int ans = INT_MIN;
        int m = matrix.size(), n = matrix[0].size();
        // 枚举上边界
        for (int i = 0; i < m; ++i) {
            vector<int> sum(n);
            // 枚举下边界
            for (int j = i; j < m; ++j) {
                for (int c = 0; c < n; ++c) {
                    // 更新每列的元素和
                    sum[c] += matrix[j][c];
                }
                set<int> sumSet{0};
                int s = 0;
                for (int v : sum) {
                    s += v;
                    auto lb = sumSet.lower_bound(s - k);
                    if (lb != sumSet.end()) {
                        ans = max(ans, s - *lb);
                    }
                    sumSet.insert(s);
                }
            }
        }
        return ans;
    }






};














