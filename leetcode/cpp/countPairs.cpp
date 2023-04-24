





#include <unordered_map>
#include <vector>


using namespace std;
class Solution {
private:
	int gcd(int a, int b) {
    	int r;
    	while (b> 0) {
        	r = a % b;
        	a = b;
        	b = r;
    	}
    	return a;
	}

public:
	long long countPairs(vector<int>& nums, int k) {
		vector<int> divisors;
		for (int d = 1; d * d <= k; ++d) {
			// 预处理 k 的所有因子
			if (k % d == 0) {
				divisors.push_back(d);
				if (d * d < k) {
					divisors.push_back(k / d);
				}
			}
		}
		long long ans = 0;
		unordered_map<int, int> cnt;
		for (int v : nums) {
			ans += cnt[k / gcd(v, k)];
			for (int d : divisors) {
				if (v % d == 0) {
					++cnt[d];
				}
			}
		}
		return ans;
	}
};











