
#include <vector>


using namespace std;


// 并查集模板
class UnionFind {
public:
	vector<int> parent;
	vector<int> size;
	int n;
	// 当前连通分量数目
	int setCount;

public:
	UnionFind(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1) {
		iota(parent.begin(), parent.end(), 0);
	}

	int findset(int x) {
		return parent[x] == x ? x : parent[x] = findset(parent[x]);
	}

	bool unite(int x, int y) {
		x = findset(x);
		y = findset(y);
		if (x == y) {
			return false;
		}
		if (size[x] < size[y]) {
			swap(x, y);
		}
		parent[y] = x;
		size[x] += size[y];
		--setCount;
		return true;
	}

	bool connected(int x, int y) {
		x = findset(x);
		y = findset(y);
		return x == y;
	}
};

class Solution {
public:
	int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
		// 编号为 n 的节点是超级节点 s
		// 编号为 n + 1 的节点是超级节点 t
		int n = row * col;
		auto uf = UnionFind(n + 2);
		vector<vector<int>> valid(row, vector<int>(col));
		int ans = 0;
		for (int i = n - 1; i >= 0; --i) {
			int x = cells[i][0] - 1, y = cells[i][1] - 1;
			valid[x][y] = true;
			// 并查集是一维的， (x, y)坐标是二维的， 需要进行转换
			int id = x * col + y;
			if (x - 1 >= 0 && valid[x - 1][y]) {
				uf.unite(id, id - col);
			}
			if (x + 1 < row && valid[x + 1][y]) {
				uf.unite(id, id + col);
			}
			if (y - 1 >= 0 && valid[x][y - 1]) {
				uf.unite(id, id - 1);
			}
			if (y + 1 < col && valid[x][y + 1]) {
				uf.unite(id, id + 1);
			}
			if (x == 0) {
				uf.unite(id, n);
			}
			if (x == row - 1) {
				uf.unite(id, n + 1);
			}
			if (uf.connected(n, n + 1)) {
				ans = i;
				break;
			}
		}
		return ans;
	}
};
























