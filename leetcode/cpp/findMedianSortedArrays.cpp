


class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int>& nums_min = nums1.size() <= nums2.size() ? nums1 : nums2;
		vector<int>& nums_max = nums1.size() > nums2.size() ? nums1 : nums2;
		int m = nums_min.size(), n = nums_max.size();
		int totalLeft = (m + n + 1) / 2;

		// 在 nums1 的区间 [0, m] 里查找恰当的分割线，
		// 使得 nums1[i - 1] <= num2[j] && nums2[j -1] <= nums1[i]
		int left = 0;
		int right = m;

		while (left < right) {
			int i = left + (right - left + 1) / 2;
			int j = totalLeft - i;
			if (nums_min[i - 1] > nums_max[j]) {
				// 下一轮搜索的区间 [left, i - 1]
				right = i - 1;
			} else {
				// 下一轮搜索的区间 [i, right]
				left = i;
			}
		}

		int i = left;
		int j = totalLeft - i;
		int nums1LeftMax = i == 0 ? INT_MIN : nums_min[i - 1];
		int nums1RightMin = i == m ? INT_MAX : nums_min[i];
		int nums2LeftMax = j == 0 ? INT_MIN : nums_max[j - 1];
		int nums2RightMin = j == n ? INT_MAX : nums_max[j];

		if ((m + n) % 2 == 1) {
			return max(nums1LeftMax, nums2LeftMax);
		} else {
			return (double)(max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2;
		}
	}
};











