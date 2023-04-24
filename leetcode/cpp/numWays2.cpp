
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
	int numWays(int n, vector<vector<int>>& relation, int k) {
		vector<vector<int>> edges(n);
		for (auto& edge : relation) {
			int src = edge[0], dst = edge[1];
			edges[src].push_back(dst);
		}

		int steps = 0;
		queue<int> que;
		que.push(0);
		while (!que.empty() && steps < k) {
			steps++;
			int size = que.size();
			for (int i = 0; i < size; ++i) {
				int index = que.front();
				que.pop();
				for (auto& nextIndex : edges[index]) {
					que.push(nextIndex);
				}
			}
		}

		int ways = 0;
		if (steps == k) {
			while (!que.empty()) {
				if (que.front() == n - 1) {
					ways++;
				}
				que.pop();
			}
		}
		return ways;
	}










};














