
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;


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

		vector<int> p(m);
		iota(p.begin(), p.end(), 0);
		int ans = 0;
		do {
			int cur = 0;
			for (int i = 0; i < m; ++i) {
				cur += g[i][p[i]];
			}
			ans = max(ans, cur);
		} while (next_permutation(p.begin(), p.end()));
		return ans;
	}












};

























