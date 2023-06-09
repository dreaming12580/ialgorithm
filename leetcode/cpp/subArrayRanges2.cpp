#include <vector>
#include <stack>

using namespace std;

//----------------------------------------------------------------
// 其中 minLeft[i] 表示 nums[i] 左侧最近的比它小的数的下标，
// 其中 minRight[i] 表示 nums[i] 右侧最近的比它小的数的下标
// 其中 maxLeft[i] 表示 nums[i] 左侧最近的比它大的数的下标，
// 其中 maxRight[i] 表示 nums[i] 右侧最近的比它大的数的下标 


class Solution {
public:
	long long subArrayRanges(vector<int>& nums) {
		int n = nums.size();
		vector<int> minLeft(n), minRight(n), maxLeft(n), maxRight(n);
		stack<int> minStack, maxStack;
		for (int i = 0; i < n; ++i) {
			while (!minStack.empty() && nums[minStack.top()] > nums[i]) {
				minStack.pop();
			}
			minLeft[i] = minStack.empty() ? -1 : minStack.top();
			minStack.push(i);
			
			// 如果 nums[maxStack.top()] == nums[i], 那么根据定义,
			// nums[maxStack.top()] 逻辑上小于 nums[i], 因为 maxStack.top() < i
			while (!maxStack.empty() && nums[maxStack.top()] <= nums[i]) {
				maxStack.pop();
			}
			maxLeft[i] = maxStack.empty() ? -1 : maxStack.top();
			maxStack.push(i);
		}
		minStack = stack<int>();
		maxStack = stack<int>();
		for (int i = n - 1; i >= 0; --i) {
			// 如果 nums[minStack.top()] == nums[i], 那么根据定义
			// nums[minStack.top()] 逻辑上大于 nums[i], 因为 minStack.top() > i
			while (!minStack.empty() && nums[minStack.top()] >= nums[i]) {
				minStack.pop();
			}
			minRight[i] = minStack.empty() ? n : minStack.top();
			minStack.push(i);

			while (!maxStack.empty() && nums[maxStack.top()] < nums[i]) {
				maxStack.pop();
			}
			maxRight[i] = maxStack.empty() ? n : maxStack.top();
			maxStack.push(i);
		}
		long long sumMax = 0, sumMin = 0;
		for (int i = 0; i < n; ++i) {
			sumMax += static_cast<long long>(maxRight[i] - i) * (i - maxLeft[i]) * nums[i];
			sumMin += static_cast<long long>(minRight[i] - i) * (i - minLeft[i]) * nums[i];
		}
		return sumMax - sumMin;
	}
};













