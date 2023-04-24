
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
public:
	vector<int> processQueries(vector<int>& queries, int m) {
		int n = queries.size();
		BIT bit(m + n);

		vector<int> pos(m + 1);
		for (int i = 1; i <= m; ++i) {
			pos[i] = n + i;
			bit.update(n + i, 1);
		}

		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			int& cur = pos[queries[i]];
			bit.update(cur, -1);
			ans.push_back(bit.query(cur));
			cur = n - i;
			bit.update(cur, 1);
		}
		return ans;
	}
};


