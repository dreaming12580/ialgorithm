
#include <vector>
#include <string>

using namespace std;



class Solution {
private:
	void flood(vector<string>& grid, vector<vector<bool>>& visited,
			int x, int y, char& c, bool& ok, int& count) {
		int m = grid.size();
		int n = grid[0].size();
		if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0') {
			//当前格为走廊，标记ok = false 并返回
			ok = false;
			return;
		}
		if (!ok ||visited[x][y] || grid[x][y] != c) {
			//  当前格已访问或者不连通， 直接返回
			return;
		}
		count++;
		visited[x][y] = true;

		flood(grid, x + 1, y, c, ok, count);
		flood(grid, x - 1, y, c, ok, count);
		flood(grid, x, y + 1, c, ok, count);
		flood(grid, x, y - 1, c, ok, count);
	}






public:
	int largestArea(vector<string>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		bool ok = true;
		int count = 0; 
		int res = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!visited[i][j]) {
					ok = true;
					count = 0;
					flood(grid, visited, i, j, grid[i][j], ok, count);
					if (ok) {
						res = max(res, count);
					}
				}
			}
		}
		return res;
	}
};
















