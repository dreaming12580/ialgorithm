#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int res = 0;
    int tmp = 0;
public:
    void backtracing(vector<vector<int>>& data, int row, int col) {
        int lx = data.size();
        int ly = data[0].size();

        // row 超过index, 回溯终止， 计算max
        if (row >= lx) {
            res = max(res, tmp);
            return;
        }
        // col 超过index, 换行，继续回溯
        if (col >= ly) {
            backtracing(data, row + 1, 0);
            return;
        }
        // 当前节点坏了 或者不能放置跳过该节点
        if (data[row][col] == -1 || data[row][col] == 1) {
            backtracing(data, row, col + 1);
            return;
        }

        // 横着放
        bool h = false;
        if (col + 1 < ly && data[row][col + 1] == 0) {
            h = true;
            data[row][col] = 1;
            data[row][col + 1] = 1;
            tmp++;
            backtracing(data, row, col+2);
            data[row][col] = 0;
            data[row][col + 1]= 0;
            tmp--;
        }

        // 竖着放
        bool v = false;
        if (row + 1 < lx && data[row + 1][col] == 0) {
            v = true;
            data[row][col] = 1;
            data[row+1][col] = 1;
            tmp++;
            backtracing(data, row, col+1);
            data[row][col] = 0;
            data[row+1][col] = 0;
            tmp--;
        }

        // 横竖都不能放时， 跳两格
        if (!h && !v) {
            backtracing(data, row, col+2);
        }
    }

    int domino(int n, int m, vector<vector<int>>& broken) {
        vector<vector<int>> data(n, vector<int>(m, 0));
        for (int i = 0; i < broken.size(); i++) {
            int x = broken[i][0];
            int y = broken[i][1];
            data[x][y] = -1;
        }
        backtracing(data, 0, 0);
        return res;
    }
};





