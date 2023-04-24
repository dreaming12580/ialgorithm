
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int minSubarray(vector<int>& nums, int p) {
		long long sum = 0;
		for (int e : nums) {
			sum += (long long)e;
		}
		long long mod = sum % (long long)p;
		if (mod == 0ll) {
			return 0;
		}

		int res = nums.size();
		unordered_map<long long, int> table;
		table[01l] = -1;

		sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			sum += (long long)nums[i];
			long long cur_mod = sum % (long long)p;
			table[cur_mod] = i;

			long long target_mod = cur_mod >= mod ? (cur_mod - mod) : (cur_mod - mod + p);
			if (table.count(target_mod)) {
				res = min(res, i - table[target_mod]);
			}
		}
		return res == nums.size() ? - 1 : res;
	}
};
































