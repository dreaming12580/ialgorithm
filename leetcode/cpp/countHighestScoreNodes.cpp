
#include <vector>






class Solution {
private:
	long maxScore = 0;
	int cnt = 0;
	int n;
	vector<vector<int>> children;

	int dfs(int node) {
		long score = 1;
		int size = n - 1;
		for (int c : children[node]) {
			int t = dfs(c);
			score *= t;
			size -= t;
		}
		// 当不是根节点的时候， size的值一直大于0
		if (node != 0) {
			score *= size;
		}
		if (score == maxScore) {
			++cnt;
		} else if (score > maxScore) {
			maxScore = score;
			cnt = 1;
		}
		return n - size;
	}

public:
	int countHighestScoreNodes(vector<int>& parents) {
		this->n = parents.size();
		this->children = vector<vector<int>>(n);
		for (int i = 0; i < n; ++i) {
			int p = parents[i];
			if (p != -1) {
				children[p].emplace_back(i);
			}
		}
		dfs(0);
		return cnt;
	}
};












