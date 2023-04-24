
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> ugly = {1};        
        auto cmp = [] (pair<int, int> f, pair<int, int> s) {
            return f.first > s.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < m; ++i) {
            pq.emplace(primes[i], 0);
        }
        while (!pq.empty()) {
            if (ugly.size() == n) {
                break;
            }
            const pair<int, int> p = pq.top();
            pq.pop();
            if (ugly.back() != p.first) {
                ugly.push_back(p.first);
            }
            if (p.second + 1 > ugly.size()) {
                continue;
            }
            int val = p.first / ugly[p.second];
            val *= ugly[p.second + 1];
            pq.emplace(val, p.second + 1);
        }
        return ugly[n - 1];
    }
};
