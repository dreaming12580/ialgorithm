#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        int n = increase.size();
        vector<int> a(n + 1, 0);
        vector<int> b(n + 1, 0);
        vector<int> c(n + 1, 0);
        for (int i = 0; i < n; i++) {
            a[i + 1] = a[i] + increase[i][0];
            b[i + 1] = b[i] + increase[i][1];
            c[i + 1] = c[i] + increase[i][2];
        }
        int m = requirements.size();
        vector<int> res;
        for (int i = 0; i < m; i++) {
            int x = requirements[i][0], y = requirements[i][1], z = requirements[i][2];
            int loc_a = lower_bound(a.begin(), a.end(), x) - a.begin();
            int loc_b = lower_bound(b.begin(), b.end(), y) - b.begin();
            int loc_c = lower_bound(c.begin(), c.end(), z) - c.begin();

            int loc = max(loc_a, max(loc_b, loc_c));
            if (loc > n) {
                res.push_back(-1);
            } else {
                res.push_back(loc);
            }
        }
        return res;
    }
};








