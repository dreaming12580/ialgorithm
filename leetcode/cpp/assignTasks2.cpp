

#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;


class Solution {
private:
    using PII = pair<int, int>;
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int i, int j) {
            return (servers[i] < servers[j]) || (servers[i] == servers[j] && i < j);
        });
        vector<int> res;
        priority_queue<PII, vector<PII>, greater<PII>> busy;
        priority_queue<int, vector<int>, greater<int>> idle;
        for (int i = 0; i< n; ++i) {
            idle.push(i);
        }
        int ts = 0;
        auto release = [&]() {
            while (!busy.empty() && busy.top().first <= ts) {
                idle.push(busy.top().second);
                busy.pop();
            }
        };

        for (int i = 0; i < m; ++i) {
            ts = max(ts, i);
            release();
            if (idle.empty()) {
                ts = busy.top().first;
                release();
            }
            busy.push(PII(ts + tasks[i], idle.top()));
            res.push_back(ids[idle.top()]);
            idle.pop();
        }
        return res;
    }
};










