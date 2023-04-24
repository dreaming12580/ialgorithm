

class Solution {

public:

	int minSwap(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int a = 0, b = 1;
		for (int i = 1; i < n; ++i) {
			int at = a, bt = b;
			a = b = n;
			// s1 与 s2 是单调递增的情况
			if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
				a = min(a, at);
				b = min(b, bt + 1);
			}
			// s1 与 s2 交换后是单调递增的情况
			if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
				a = min(a, bt);
				b = min(b, at + 1);
			}
		}
		return min(a, b);
	}
};














