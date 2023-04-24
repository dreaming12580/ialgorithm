#include <vector>
#include <unordered_map>
using namespace std;

const int mx = 100001;
vector<int> divisors[mx];

// 预处理每个数的所有因子， 时间复杂度 O(MlogM), M = 1e5
int init = []() {
	for (int i = 1; i < mx; ++i) {
		for (int j = i; j < mx; j += i) {
			divisors[j].push_back(i);
		}
	}
	return 0;
} ();

class Solution {
public:
	long long countPairs(vector<int>& nums, int k) {
		long long ans = 0;
		unordered_map<int, int> cnt;
		for (int v : nums) {
			ans += cnt[k / gcd(v, k)];
			// 将 v 的所有因子，填充到cnt 统计中
			for (int d : divisors[v]) {
				++cnt[d];
			}
		}
		return ans;
	}
};








