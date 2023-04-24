

class UnionFind {
public:
	UnionFind(int n) {
		parent = vector<int>(n);
		rank = vector<int>(n); 
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}
	}

	void uni(int x, int y) {
		int rootx = find(x);
		int rooty = find(y);
		if (rootx != rooty) {
			if (rank[rootx] > rank[rooty]) {
				parent[rooty] = rootx;
			} else if (rank[rootx] < rank[rooty]) {
				parent[rootx] = rooty;
			} else {
				parent[rooty] = rootx;
				rank[rootx]++;
			}





		}
	}

	int find(int x) {
		if (parent[x] != x) {
			parent[x] = find(parent[x]);
		}
		return parent[x];
	}

	bool connect(int x, int y) {
		return find(x) == find(y);
	}

private:
	vector<int> parent;
	vector<int> rank;
};

class Solution {
public:
	bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
		if (source == destination) {
			return true;
		}
		UnionFind uf(n);
		for (auto edge : edges) {
			uf.uni(edge[0], edge[1]);
		}
		return uf.connect(source, destination);
	}
};















