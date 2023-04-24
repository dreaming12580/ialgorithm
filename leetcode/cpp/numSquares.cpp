
#include <vector>


using namespace std;


class Solution {
public:
	int numSquares(int n) {
		// f[i] 表示最少需要多少个数的平方来表示整数 i
		vector<int> f(n + 1);
		for (int i = 1; i <= n; ++i) {
			int minn = INT_MAX;
			for (int j = 1; j * j <= i; ++j) {
				minn = min(minn, f[i - j * j]);
			}
			f[i] = minn + 1;
		}
		return f[n];
	}
};

































