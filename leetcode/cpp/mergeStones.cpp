
class Solution {
private:
	static constexpr int inf = 0x3f3f3f3f;
	// d[l][r][t] 表示将[l, r]合并为 t(1 <= t <= k)堆的最低成本
	vector<vector<vector<int>>> d;
	vector<int> sum;
	int k;

public:
	int get(int l, int r, int t) {
		// 若 d[l][r][t] 不为 -1, 表示已经在之前的递归被求解过，直接返回答案
		if (d[l][r][t] != - 1) {
			return d[l][r][t];
		}
		// 当石头堆数小于 t 时， 一定无解
		if (t > r - l + 1) {
			return inf;
		}
		if (t == 1) {
			int res = get(l, r, k);
			if (res == inf) {
				return d[l][r][t] = inf;
			}
			return d[l][r][t] = res + (sum[r] - (l == 0 ? 0 : sum[l - 1]));
		}
		int val = inf;
		for (int p = l; p < r; p += (k - 1)) {
			val = min(val, get(l, p, 1) + get(p + 1, r, t - 1));
		}
		return d[l][r][t] = val;
	}

	int mergeStones(vector<int>& stones, int k) {
		int n = stones.size();
		if ((n - 1) % (k - 1) != 0) {
			return -1;
		}
		this->k = k;
		d = vector(n, vector(n, vector<int>(k + 1, -1)));
		sum = vector<int>(n, 0);

		// 初始化
		for (int i = 0, s = 0; i < n; ++i) {
			d[i][i][1] = 0;
			s += stones[i];
			sum[i] = s;
		}
		int res = get(0, n - 1, 1);
		return res;
	}
};













