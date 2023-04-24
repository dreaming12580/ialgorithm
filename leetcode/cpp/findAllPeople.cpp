
#include <vector>


using namespace std;

class Solution {

public:
	vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
		// 保存已经知晓秘密的专家
		vector<bool> known(n);
		known[0] = true;
		known[firstPerson] = true;

		int max_time = 0;
		for (auto& meet : meetings) {
			max_time = max(max_time, meet[2]);
		}
		// 保证按时间顺序进行处理， 同一时间一起处理
		vector<vector<pair<int, int>>> time(max_time + 1);
		for (auto& meet : meetings) {
			time[meet[2]].emplace_back(meet[0], meet[1]);
		}

		// 保存会议的专家之间的连接信息
		vector<vector<int>> adj(n);
		for (int i = 1; i <= max_time; ++i) {
			if (time[i].empty()) {
				continue;
			}

			// 保存已经放入Queue队列里的元素， 防止重复死循环遍历
			unordered_set<int> vis;
			// 保存当前时间已经知晓秘密的专家
			queue<int> q;
			for (auto& [u, v] : time[i]) {
				adj[u].emplace_back(v);
				adj[v].emplace_back(u);
				if (known[u] && !vis.count(u)) {
					vis.insert(u);
					q.push(u);
				}
				if (known[v] && !vis.count(v)) {
					vis.insert(v);
					q.push(v);
				}
			}
			// 需要q，是为了防止对vis同时进行遍历与插入元素
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int v : adj[u]) {
					if (!vis.count(v)) {
						known[v] = true;
						vis.insert(v);
						q.push(v);
					}
				}
			}

			for (auto& [u, v] : time[i]) {
				adj[u].clear();
				adj[v].clear();
			}
		}

		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			if (known[i]) {
				ans.push_back(i);
			}
		}
		return ans;
	}
};





















