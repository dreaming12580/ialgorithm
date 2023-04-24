#include <queue>
#include <vector>


using namespace std;

class Solution {
private:
    using PII = pair<int, int>;

public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size();
        int n = tasks.size();

        // 工作中的服务器， 存储二元组(t, idx)
        priority_queue<PII, vector<PII>, greater<PII>> busy;
        // 空闲的服务器， 存储二元组(w, idx)
        priority_queue<PII, vector<PII>, greater<PII>> idle;
        for (int i = 0; i < m; ++i) {
            idle.emplace(servers[i], i);
        }
        int ts = 0;
        // 将优先队列 busy 中满足 t <= ts 依次取出并放入优先队列 idle
        auto release = [&] () {
            while (!busy.empty() && busy.top().first <= ts) {
                auto&& [_, idx] = busy.top();
                idle.emplace(servers[idx], idx);
                busy.pop();
            }
        };

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ts = max(ts, i);
            release();
            if (idle.empty()) {
                ts = busy.top().first;
                release();
            }
            auto&& [_, idx] = idle.top();
            ans.push_back(idx);
            busy.emplace(ts + tasks[i], idx);
            idle.pop();
        }







    }












};































