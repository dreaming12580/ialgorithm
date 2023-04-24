

#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();

        for (int i = 0; i < m; ++i) {
            // 队首对应的位置
            int front_pos = n - 1;
            for (int j = n - 1; j >= 0; --j) {
                if (box[i][j] == '*') {
                    // 遇到障碍物， 清空队列
                    front_pos = j - 1;
                } else if (box[i][j] == '#') {
                    if (front_pos > j) {
                        // 如果队列不为空， 石头就会下落
                        box[i][front_pos] = '#';
                        box[i][j] = '.';
                        --front_pos;
                    } else {
                        front_pos = j - 1;
                    }
                }
            }
        }

        // 将矩阵顺时针旋转 90度放入答案
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][m -i -1] = box[i][j];
            }
        }
        return ans;
    }
};









