

#include <vector>
#include <queue>

using namespace std;



class Solution {
public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<vector<int>> rg(n);  
		vector<int> outDeg(n); 
		for (int x = 0; x < n; ++x) {
			for (int y : graph[x]) {
				rg[y].push_back(x);
			}
			outDeg[x] = graph[x].size();
		}

		queue<int> q;
		for (int i = 0; i < n; ++i) {
			if (outDeg[i] == 0) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int y = q.front();
			q.pop();
			for (int x : rg[y]) {
				if (--outDeg[x] == 0) {
					q.push(x);
				}
			}
		}

		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			if (outDeg[i] == 0) {
				ans.push_back(i);
			}
		}
		return ans;
	}
};



























