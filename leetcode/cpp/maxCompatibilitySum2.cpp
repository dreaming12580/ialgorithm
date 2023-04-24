#include <vector>

using namespace std;

/*
记录我对状态转移方程的理解：
mask决定了两个信息，分配的学生个数和可供匹配的老师编号。
对于编号c-1学生来说，可供选择的老师编号就是mask二进制为1的位置，
所以枚举所有1位置，并将该位置0得到上一个状态 mask\i ，
此状态包含学生[0,..,c-2]和不含该位置的c-1个老师。
所以状态转移方程为 f[mask] = max(f[mask\i] + g[c - 1][i])
*/

class Solution {
public:
	int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
		int m = students.size();
		int n = students[0].size();
		vector<vector<int>> g(m, vector<int>(m));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < m; ++j) {
				for (int k = 0; k < n; ++k) {
					g[i][j] += (students[i][k] == mentors[j][k]);
				}
			}
		}

		vector<int> f(1 << m);
		for (int mask = 1; mask < (1 << m); ++mask) {
			int c = __builtin_popcount(mask);
			for (int i = 0; i < m; ++i) {
				// 判断 mask的第 i 位是否为 1
				if (mask & (1 << i)) {
					f[mask] = max(f[mask], f[mask ^ (1 << i)] + g[c - 1][i]);
				}
			}
		}
		return f[(1 << m) - 1];
	}
};








