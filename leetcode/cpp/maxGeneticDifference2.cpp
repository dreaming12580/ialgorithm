#include <vector>
#include <iostream>



using namespace std;


class Solution {
private:
	// 最大的数的二进制表示不会超过 18 位
	// 那么二进制位的下标范围是 [0, 17]
	static constexpr int MAXD = 17;

public: 
	vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
		int n = parents.size();
		
		// 将parents 存储为树的形式， 方便进行深度优先遍历
		vector<vector<int>> edges(n);
		// 找出根节点
		int root = -1;
		for (int i = 0; i < n; ++i) {
			if (parents[i] == - 1) {
				root = i;
			} else {
				edges[parents[i]].push_back(i);
			}
		}

		int m = queries.size();
		// 使用离线的思想， stored[i] 存储了所有节点 i 对应的询问
		vector<vector<pair<int, int>>> stored(n);
		vector<int> ans(m);
		for (int i = 0; i < m; ++i) {
			stored[queries[i][0]].emplace_back(i, queries[i][1]);
		}
	}
}































