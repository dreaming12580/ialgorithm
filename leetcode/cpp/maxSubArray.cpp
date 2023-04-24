

#include <vector>
#include <numeric>
#include <climits>
using namespace std;

class Solution {


public:
    vector<int> maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int dp_i = nums[0];
        vector<int> ans(2);   // 用来记录答案
        int begin = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (dp_i > 0) {
                dp_i += nums[i];
            } else {
                dp_i = nums[i];
                begin = i; // 当nums[i]自立门户时候，我们记录下子序列起始位置
            }
            if (dp_i > max_sum) {
                max_sum = dp_i;
                ans[0] = begin;
                ans[1] = i;
            }
        }
        return ans;
    }
};














