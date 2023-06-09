#include <vector>
#include <function>

using namespace std;



struct BIT : vector<int> {
	BIT(int n = 0) : vector<int>(n) {}   
	void add(int p, int x) { 
		for (; p < (int)size(); p += p & -p) {
			at(p) += x;
		}
	}
	int sum(int p) {
		int res = 0;  
		for (; p; p -= p & -p) {
			res += at(p);
		}
		return res;
	}	
	int query(int x) {
		// find the smallest positive integer p such that sum(p) >= x
		int L = 0, R = size();
		while (L + 1 < R) {
			int m = (L + R) >> 1; 
			if (at(m) < x) {
				x -= at(m);
				L = m;
			} else {
				R = m;
			}
		}
		return R;
	}
};

class LockingTree {
public:
	vector<int> size, p, q, mark;
	BIT down, up;
	LockingTree(vector<int>& parent): size(parent.size()), p(parent.size()), q(parent.size() + 1), mark(parent.size(), -1), up(parent.size() + 1) {
		vector<vector<int>> children(parent.size());
		for (int i = 1; i < (int)parent.size(); ++i) {
			children[parent[i]].push_back(i);
		}
		int timer = 0;
		function<void(int)> dfs = [&] (int u) {
			size[u] = 1;
			p[u] = timer += 1;
			q[timer] = u;
			for (int v : children[u]) {
				dfs(v);
				size[u] += size[v];
			}
		};
		dfs(0);
		int k = 1;
		while (k <= (int)parent.size()) {
			k <<= 1;
		}
		down.resize(k);
	} 
	bool lock(int num, int user) {
		if (mark[num] != -1) {
			return false;
		}
		mark[num] = user;
		down.add(p[num], 1);
		up.add(p[num], 1);
		up.add(p[num] + size[num], -1);
		return true;
	}
	bool unlock(int num, int user) {
		if (mark[num] != user) {
			return false;
		}
		mark[num] = -1;
		down.add(p[num], -1);
		up.add(p[num], -1);
		up.add(p[num] + size[num], 1);
		return true;
	}
	bool upgrade(int num, int user) {
		if (up.sum(p[num])) {
			return false;
		}
		int L = down.sum(p[num] - 1), R = down.sum(p[num] + size[num] - 1);
		if (L == R) {
			return false;
		}
		for (int i = 0; i < R - L; ++i) {
			int k = down.query(L + 1);
			mark[q[k]] = -1;
			down.add(k, -1);
			up.add(k, -1);
			up.add(k + size[q[k]], 1);
		}
		lock(num, user);
		return true;
	}
};



















