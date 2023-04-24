
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:

    // 很多小伙伴对getID有点迷惑,就是为什么取负数,如w=10, 
	// 因为非负数是0~9，10~19...这种一组，
	// 而负数是-1~-10, -11~-20...这些是一组，
	// 如果-1~-10直接除以10，会被分到两组中，而不是-1这一组，
	// 所以先+1变成-0--9,与正数一致，再除以10，最后减1，
	// 正好是-1这一组，其它组也是同理
	// 最后减1， 是为了-1组与0组进行错开
	int getID(int x, long w) {
		return x < 0 ? (x + 1ll) / w  - 1 : x / w;
	}

	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		unordered_map<int, int> mp;
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			long x = nums[i];
			int id = getID(x, t + 1ll);
			if (mp.count(id)) {
				return true;
			}
			if (mp.count(id - 1) && abs(x - mp[id - 1]) <= t) {
				return true;
			}
			if (mp.count(id + 1) && abs(x - mp[id + 1]) <= t) {
				return true;
			}
			mp[id] = x;
			if (i >= k) {
				mp.erase(getID(nums[i - k], t + 1ll));
			}
		}	
		return false;
	}
};
































