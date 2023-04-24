
#include <vector>

using namespace std;

class Solution {

public:
    int findTheWinner(int n, int k) {
        int cur = 1;
        vector<int> v(n);
        for (int i = 1; i <= n; ++i) {
            v[i-1] = i;
        }
        auto d = k - 1;
        int idx = 0;
        while (v.size() > 1) {
            auto pos = (idx + d) % v.size();
            v.erase(v.begin() + pos);
            idx = pos;
        }
        return v[0];
    }
};












