#include <vector>
#include <string>







class Solution {
private:
	map<long long, long long> mp;
	static constexpr int mod = 1e9+7;

	long long fun(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {
		if (target == 0) {
			return 0;
		}
		if (mp.count(target)) {
			return mp[target];
		}
		long long s = (long long) target * inc;
		for (int i = 0; i < jump.size(); ++i) {
			s = min(s, fun(target/ jump[i], inc, dec, jump, cost) +
					cost[i] + (long long)(target % jump[i]) * inc);
			if (target > 1 && (target % jump[i] != 0)) {
				s = min(s, fun(target / jump[i] + 1, inc , dec, jump, cost) +
						cost[i] + (long long)(jump[i] - target % jump[i]) * dec);
			}
		}
		return mp[target] = s;
	}


public:
	int busRapidTransit(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {
		mp.clear();
		return fun(target, inc, dec, jump, cost) % mod;
	}




};





































