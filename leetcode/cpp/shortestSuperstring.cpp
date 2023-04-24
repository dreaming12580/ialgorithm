

#include <vector>
#include <string>


using namespace std;


class Solution {

public:
	string shortestSuperString(vector<string> A) {
		int n = A.size();

		// populate overlaps
		vector<vector<int>> overlaps(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int m = min(A[i].length(), A[j].length());
				for (int k = m; k >= 0; --k) {
					int len_i = A[i].length();
					if (A[i].substr(len_i - k) == A[j].substr(0, k)) {
						overlaps[i][j] = k;
						break;
					}
				}
			}
		}
		// dp[mask][i] 是 most overlap with mask, ending with ith element
		vector<vector<int>> dp(1 << n, vector<int>(n));
		vector<vector<int>> parent(1 << n, vector<int>(n));
		// 对于这种mask的情况下， 以A[bit]为结尾的字符串，更新dp[mask][bit]的重复部分的最大长度
		for (int mask = 0; mask < (1 << n); ++mask) {
			fill(parent[mask].begin(), parent[mask].end(), -1);
			for (int bit = 0; bit < n; ++bit) {
				if ((mask >> bit) & 1 > 0) {
					int pmask = mask ^ (1 << bit);
					if (pmask == 0) {
						continue;
					}
					for (int i = 0; i < n; ++i) {
						if ((pmask >> i) & 1 > 0) {
							// 对于pmask里的每个i, 计算重复部分的最大长度
							int val = dp[pmask][i] + overlaps[i][bit];
							if (val > dp[mask][bit]) {
								dp[mask][bit] = val;
								parent[mask][bit] = i;
							}
						}
					}
				}
			}
		}

		vector<int> perm(n);
		vector<bool> seen(n);
		int t = 0;
		int mask = (1 << n) - 1;

		// p: the last element of perm (last word writen left to right)
		int p = 0;
		// 所有元素都取到的情况下， p是重合部分最大长度的后缀A[p]
		for (int j = 0; j < n; ++j) {
			if (dp[(1 << n) - 1][j] > dp[(1 << n) - 1][p]) {
				p = j;
			}
		}
		// parent 表示末尾是p的情况下， 前一个重复部分的最大长度，是哪个A[i]字符串
		while (p != -1) {
			perm[t++] = p;
			seen[p] = true;
			int p2 = parent[mask][p];
			mask ^= 1 << p;
			p = p2;
		}

		// 调整 perm的顺序
		for (int i = 0; i < t / 2; ++i) {
			int v = perm[i];
			perm[i] = perm[t - 1 - i];
			perm[t - 1 - i] = v;
		}

		// 填充剩余的 words
		for (int i = 0; i < n; ++i) {
			if (!seen[i]) {
				perm[t++] = i;
			}
		}

		string ans = A[perm[0]];
		for (int i = 1; i < n; ++i) {
			int overlap = overlaps[perm[i - 1]][perm[i]];
			ans.append(A[perm[i]].substr(overlap));
		}
		return ans;
	}
};



















