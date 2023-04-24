

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        vector<int> ans(3, 0);
        int n = matrix.size();
        if (n == 0) {
            return {};
        } else if (n == 1) {
            if (matrix[0][0] == 0) {
                return {0, 0, 1};
            } else {
                return {};
            }
        }
        // cnt[r][c][0/1], 0右侧， 1下侧
        vector<vector<vector<int>>> cnt(n, vector<vector<int>>(n, vector<int>(2)));
        for (int r = n - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (matrix[r][c] == 1) {
                    cnt[r][c][0] = cnt[r][c][1] = 0;
                } else {
                    // 统计cnt[r][c][0/1]
                    if (r < n - 1) {
                        cnt[r][c][1] = cnt[r + 1][c][1] + 1;
                    } else {
                        cnt[r][c][1] = 1;
                    }

                    if (c < n - 1) {
                        cnt[r][c][0] = cnt[r][c + 1][0] + 1;
                    } else {
                        cnt[r][c][0] = 1;
                    }
                    // 更新当前最大子方阵
                    // 最大可能的边长
                    int len = min(cnt[r][c][0], cnt[r][c][1]);
                    // 要答案r,c 最小， 所以带等号
                    while (len >= ans[2]) {
                        if (cnt[r + len - 1][c][0] >= len &&
                            cnt[r][c + len - 1][1] >= len) {
                            // 可以构成长尾len的方阵
                            ans = {r, c, len};
                            break;
                        }
                        len--;
                    }

                }
            }
        }
        return ans;
    }
};
