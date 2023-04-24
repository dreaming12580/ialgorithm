#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> v(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                v[i + 1] = v[i] - 1;
            } else {
                v[i + 1] = v[i] + 1;
            }
        }

        unordered_map<int, int> mp;
        int max = 0;
        for (int i = 0; i <= n; ++i) {
            if (mp.find(v[i]) == mp.end()) {
                mp[v[i]] = i;
            } else if (i - mp[v[i]] > max) {
                max = i - mp[v[i]];
            }
        }

        return max;

    }
};














