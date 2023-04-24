
#include <string>
#include <vector>




using namespace std;


class Solution {
public:
	int minMutation(string start, string end, vector<string>& bank) {
		int m = start.size();
		int n = bank.size();
		vector<vector<int>> adj(n);
		int endIndex = - 1;
		for (int i = 0; i < n; ++i) {
			if (end == bank[i]) {
				endIndex = i;
			}
			for (int j = i + 1; j < n; ++j) {
				int mutations = 0;
				for (int k = 0; k < m; ++k) {
					if (bank[i][k] != bank[j][k]) {
						mutations++;
					}
					if (mutations > 1) {
						break;
					}
				}
				if (mutations == 1) {
					adj[i].emplace_back(j);
					adj[j].emplace_back(i);
				}
			}
		}
		if (endIndex == -1) {
			return -1;
		}

		queue<int> qu;
		vector<bool> visited(n, false);
		int step = 1;
		for (int i = 0; i < n; ++i) {
			int mutations = 0;
			for (int k = 0; k < m; ++k) {
				if (start[k] != bank[i][k]) {
					mutations++;
				}
				if (mutations > 1) {
					break;
				}
			}
			if (mutations == 1) {
				qu.emplace(i);
				visited[i] = true;
			}
		}
		while (!qu.empty()) {
			int sz = qu.size();
			for (int i = 0; i < sz; ++i) {
				int curr = qu.front();
				qu.pop();
				if (curr == endIndex) {
					return step;
				}
				for (auto& next : adj[curr]) {
					if (visited[next]) {
						continue;
					}
					visited[next] = true;
					qu.emplace(next);
				}
			}
			++step;
		}
		return -1;
	}
};











