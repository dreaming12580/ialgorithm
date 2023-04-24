
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
	vector<int> rearrangeArray(vector<int>& nums) {
		// 将数组排序
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int m = (n + 1) / 2;
		vector<int> res;
		for (int i = 0; i < m; ++i) {
			// 放入数值较小的第一部分元素
			res.push_back(nums[i]);
			if (i + m < n) {
				// (如果有) 放入数值较大的第二部分元素
				res.push_back(nums[i + m]);
			}
		}
		return res;
	}
};











