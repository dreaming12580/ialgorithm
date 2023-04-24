#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        int n = increase.size();
        vector<int> a(n + 1, 0);
        vector<int> b(n + 1, 0);
        vector<int> c(n + 1, 0);
        cout << "alen: " << (a.end() - a.begin()) << endl;
        for (int i = 0; i < n; i++) {
            a[i+1] = a[i] + increase[i][0];
            b[i+1] = b[i] + increase[i][1];
            c[i+1] = c[i] + increase[i][2];
        }

        vector<int> res;
        for (auto v : requirements) {
            int x = v[0], y = v[1], z = v[2];
            int loc_a = lower_bound(a.begin(), a.end(), x) - a.begin();
            int loc_b = lower_bound(b.begin(), b.end(), y) - b.begin();
            int loc_c = lower_bound(c.begin(), c.end(), z) - c.begin();
            int loc = max(loc_a, max(loc_b, loc_c));
            if (loc <= n) {
                res.push_back(loc);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> increase;
    increase.push_back(vector<int>{2, 8, 4});
    increase.push_back(vector<int>{2, 5, 0});
    increase.push_back(vector<int>{10, 9, 8});

    vector<vector<int>> requirements;
    requirements.push_back(vector<int>{2, 11, 3});
    requirements.push_back(vector<int>{15, 10, 7});
    requirements.push_back(vector<int>{9, 17, 12});
    requirements.push_back(vector<int>{8, 1, 14});

    Solution s;
    vector<int> res = s.getTriggerTime(increase, requirements);

    cout << "res:";
    for (auto v: res) {
        cout << v << " ";
    }
    cout << endl;
}


