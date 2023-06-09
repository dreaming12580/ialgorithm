#include <vector>

using namespace std;   

// 数组d[i] 表示长度为 i 的最长上升子序列的末尾元素的最小值
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int len = 1, n = (int)nums.size(); 
		if (n == 0) {
			return 0;
		}
		vector<int> d(n + 1, 0);  
		d[len] = nums[0];
		for (int i = 0; i < n; ++i) {
			if (nums[i] > d[len]) {
				d[++len] = nums[i];
			} else {
				// 如果找不到说明所有的数都比 nums[i] 大，
				// 此时要更新 d[1], 所以这里将pos 设为 0
				int l = 1, r = len, pos = 0;
				while (l <= r) {
					int mid = (l + r) >> 1;
					if (d[mid] < nums[i]) {
						pos = mid; 
						l = mid + 1;
					} else {
						r = mid - 1;
					}
				}
				d[pos + 1] = nums[i];
			}
		}
		return len;
	}
};


















