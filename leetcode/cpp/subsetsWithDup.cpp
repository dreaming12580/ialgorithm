#include <algorithm>
#include <vector>

using namespace std;





class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            t.clear();
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    // 如果满足， 说明上次相同的元素已经存储了一遍结果，这次mask跳过
                    if (i > 0 && (mask & (1 <<(i - 1))) && nums[i - 1] == nums[i]) {
                        flag = false;
                        break;
                    }
                    t.push_back(nums[i]);
                }
            }
            if (flag) {
                ans.push_back(t);
            }
        }
        return ans;





    }


};

















