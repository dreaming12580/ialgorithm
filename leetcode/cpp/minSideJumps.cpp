
#include <vector>
#include <numeric>
#include <cstdint>
#include <climits>
using namespace std;




class Solution {
private:
    static constexpr int INF = INT_MAX / 2;

public:
    int minSideJumps(vector<int>& obstacles) {
        vector<int> curr = {1, 0, 1};
        int n = obstacles.size();
        if (obstacles[0] != 0) {
            curr[obstacles[0] - 1] = INF;
        }
        for (int i = 1; i < n; ++i) {
            if (obstacles[i] == 0) {
                continue;
            }

            int t = curr[obstacles[i] - 1];
            for (int j = 0; j < 3; ++j) {
                if (j == obstacles[i - 1] - 1) {
                    continue;
                }
                curr[j] = min(curr[j], t + 1);
            }
            curr[obstacles[i] - 1] = INF;
        }
        int min_val = INF;
        for (int i = 0; i < 3; ++i) {
            min_val = min(min_val, curr[i]);
        }
        return min_val;
    }
};













