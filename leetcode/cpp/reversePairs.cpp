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

	int reversePairs(vector<int>& nums) {
		int n = nums.size();
		// 离散化
		vector<int> tmp = nums;
		sort(tmp.begin(), tmp.end());
		for (int& num : nums) {
			num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
		}

		// 树状数组统计逆序对
		BIT bit(n);
		int ans = 0;
		for (int i = n - 1; i >= 0; --i) {
			ans += bit.query(nums[i] - 1);
			bit.update(nums[i], 1);
		}
		return ans;
	}
};


