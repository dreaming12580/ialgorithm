

#include <vector>
#include <algorithm>

using namespace std;


class Solution {
private:
    int m;
    int n;
    vector<vector<bool>> visited;
    vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    void dfs(vector<vector<int>>& land, int i, int j, int& count) {
        if (i < 0 || i >= m || j < 0 || j >= n || 
            visited[i][j] || land[i][j] > 0) {
            return;
        }
        visited[i][j] = true;
        count++;
        for (const auto& dir : dirs) {
            auto ni = i + dir[0];
            auto nj = j + dir[1];
            dfs(land, ni, nj, count);
        }
    }






public:

    vector<int> pondSizes(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();
        vector<int> res;
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!visited[i][j] && land[i][j] == 0) {
                    int count = 0;
                    dfs(land, i, j, count);
                    res.push_back(count);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }


};




























