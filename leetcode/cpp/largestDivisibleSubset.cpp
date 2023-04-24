#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        // 第一步， 动态规划找出最大子集的个数、 最大子集中的最大整数
        vector<int> dp(len, 1);
        int max_size = 1;
        int max_val = dp[0];
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                // 题目中说“没有重复元素”很重要
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > max_size) {
                max_size = dp[i];
                max_val = nums[i];
            }
        }
        
        // 第二步， 倒退获取最大子集
        vector<int> res;
        if (max_size == 1) {
            res.push_back(nums[0]);
            return res;
        }

        for (int i = len - 1; i >= 0 && max_size > 0; i--) {
            if (dp[i] == max_size && max_val % nums[i] == 0) {
                res.push_back(nums[i]);
                max_val = nums[i];
                max_size--;
            }
        }
        return res;
    }
};













