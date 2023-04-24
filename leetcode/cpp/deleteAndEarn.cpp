#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        int max_val = 0;
        for (int val : nums) {
            max_val = max(max_val, val);
        }
        vector<int> sum(max_val + 1);
        for (int val : nums) {
            sum[val] += val;
        }
        return rob(sum);
    }
};



