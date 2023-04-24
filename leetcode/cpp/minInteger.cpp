
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
	string minInteger(string num, int k) {
		int n = num.size();
		vector<queue<int>> pos(10);
		for (int i = 0; i < n; ++i) {
			pos[num[i] - '0'].push(i + 1);
		}

		string ans;
		BIT bit(n);
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 10; ++j) {
				if (!pos[j].empty()) {
					// 这里的behind是移动后多出来的需要交换的次数
					int behind = bit.query(pos[j].front() + 1, n);
					int dist = pos[j].front() + behind - i;
					if (dist <= k) {
						bit.update(pos[j].front(), 1);
						pos[j].pop();
						ans += (j + '0');
						k -= dist;
						break;
					}
				}
			}
		}
		return ans;
	}

};






