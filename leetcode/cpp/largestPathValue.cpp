#include <vector>
#include <array>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;


class Solution {

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        // 邻接表
        vector<vector<int>> g(n);
        // 节点的入度统计， 用于找出拓扑排序中最开始的节点
        vector<int> indeg(n);
        for (auto&& edge : edges) {
            ++indeg[edge[1]];
            g[edge[0]].push_back(edge[1]);
        }

        // 记录拓扑排序过程中遇到的节点个数
        // 如果最终found的值不为n， 说明图中存在环
        int found = 0;
        // f存储n个节点,以当前节点为终点, 26种颜色中，每种颜色对应的最大值
        vector<array<int, 26>> f(n);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!indeg[i]) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            ++found;
            int u = q.front();
            q.pop();
            // 将节点u对应的颜色增加1
            ++f[u][colors[u] - 'a'];
            // 枚举u的后继节点v
            for (int v : g[u]) {
                --indeg[v];
                // 将 f(v,c)更新为其与f(u,c)的较大值
                for (int c = 0; c < 26; ++c) {
                    f[v][c] = max(f[v][c], f[u][c]);
                }
                if (!indeg[v]) {
                    q.push(v);
                }
            }
        }

        if (found != n) {
            return -1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, *max_element(f[i].begin(), f[i].end()));
        }
        return ans;
    }





};










