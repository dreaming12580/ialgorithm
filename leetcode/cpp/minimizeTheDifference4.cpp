#include <bitset>
#include <vector>


using namespace std;


class Solution {
public:
	int minimizeTheDifference(vector<vector<int>>& mat, int target) {
		constexpr int maxn = 4905;
		using bs = bitset<maxn>; 
		auto dp = make_unique<bs>(1), cur = make_unique<bs>();
		for (auto&& l : mat) {
			for (auto e : l) {
				*cur |= (*dp << e);
			}
			swap(dp, cur);
			*cur = {};
		}
		int ret = INT_MAX;
		for (int i = 0; i < maxn; ++i) {
			if ((*dp)[i]) {
				ret = min(ret, abs(i - target));
			}
		}
		return ret;
	}
};







