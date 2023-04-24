#include <bits/stdc++.h>

class BIT {
private:
	vector<int> tree;
	int n;

public:
	BIT(int _n) : n(_n), tree(_n + 1) {}

	static int lowbit(int x) {
		return x & (-x);
	}

	void update(int x, int d) {
		while (x <= n) {
			tree[x] += d;
			x += lowbit(x);
		}
	}

	int query(int x) const {
		int ans = 0;
		while (x) {
			ans += tree[x];
			x -= lowbit(x);
		}
		return ans;
	}

	int query(int x, int y) const {
		return query(y) - query(x - 1);
	}
};

class Solution {
private:
	static constexpr int mod = 1e9 + 7;

public:
	int createSortedArray(vector<int>& instructions) {
		int ub = *max_element(instructions.begin(), instructions.end());
		BIT bit(ub);
		long long ans = 0;
		for (int i = 0; i < instructions.size(); i++) {
			int x = instructions[i];
			int smaller = bit.query(x - 1);
			int larger = i - bit.query(x);
			ans += min(smaller, larger);
			bit.update(x);
		}
		return ans % mod;
	}
};



















