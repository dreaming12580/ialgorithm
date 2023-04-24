
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
	int minimizeTheDifference(vector<vector<int>>& A, int target) {
		int m = A.size();
		int n = A[0].size();
		bitset<5000> f[m];
		f[0] = 0;
		for (int i = 0; i < n; ++i) {
			f[0][A[0][i]] = 1;
		}
		for (int i = 1; i < m; ++i) {
			f[i] = 0;
			for (int j = 0; j < n; ++j) {
				f[i] |= (f[i - 1] << A[i][j]);
			}
		}
		int ans = 4900;
		for (int i = 1; i <= 4900; ++i) {
			if (f[n - 1][i]) {
				ans = min(ans, abs(target - i));
			}
		}
		return ans;
	}
};











