

#include <vector>


using namespace std;


class Solution {
public:
	vector<int> maxSumOfTwoSubarrays(vector<int>& nums, int k) {
		vector<int> ans;
		int sum1 = 0, maxSum1 = 0, maxSum1Idx = 0;
		int sum2 = 0, maxSum12 = 0;
		for (int i = k; i < nums.size(); ++i) {
			sum1 += nums[i - k];
			sum2 += nums[i];
			if (i >= k * 2 - 1) {
				if (sum1 > maxSum1) {
					maxSum1 = sum1;
					maxSum1Idx = i - k * 2 + 1;
				}
				if (maxSum1 + sum2 > maxSum12) {
					maxSum12 = maxSum1 + sum2;
					ans = {maxSum1Idx, i - k + 1};
				}
				sum1 -= nums[i - k * 2 + 1];
				sum2 -= nums[i - k + 1];
			}
		}
		return ans;
	}
}



















