
#include <vector>

using namespace std;
class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int low = 0, high = nums.size() - 1;
		while (low < high) {
			int mid = (high - low) >> 1 + low;
			if (nums[mid] == nums[mid ^ 1]) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}	
		return nums[low];
	}
};