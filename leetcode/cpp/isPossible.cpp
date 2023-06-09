






class Solution {
public:
	bool isPossible(int n, vector<vector<int>> &edges) {
		unordered_set<int> g[n + 1];
		for (auto &e : edges) {
			int x = e[0], y = e[1];
			g[x].insert(y);
			g[y].insert(x);
		}
		vector<int> odd;
		for (int i = 1; i <= n; ++i) {
			if (g[i].size() % 2) {
				odd.push_back(i);
			}
		}
		int m = odd.size();
		if (m == 0) {
			return true;
		}
		if (m == 2) {
			int x = odd[0], y = odd[1];
			if (!g[x].count(y)) {
				return true;
			}
			for (int i = 1; i <= n; ++i) {
				if (i != x && i != y && !g[i].count(x) && !g[i].count(y)) {
					return true;
				}
			}
			return false;
		}
		if (m == 4) {
			int a = odd[0], b = odd[1], c = odd[2], d = odd[3];
			return !g[a].count(b) && !g[c].count(d) ||
							!g[a].count(c) && !g[b].count(d) ||
							!g[a].count(d) && !g[b].count(c);
		}
		return false;
	}
};











