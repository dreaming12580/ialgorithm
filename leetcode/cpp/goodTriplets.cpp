
#include <vector>


using namespace std;




class Solution {
public:
	long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		vector<int> p(n);
		for (int i = 0; i < n; ++i) {
			p[nums1[i]] = i;
		}
		long long ans = 0;
		vector<int> tree(n + 1);
		for (int i = 1; i < n - 1; ++i) {
			// 将 p[nums2[i - 1]] + 1 加入树状数组
			for (int j = p[nums2[i - 1]] + 1; j <= n; j += j & -j) {
				++tree[j];
			}
			int y = p[nums2[i]], less = 0;
			// 计算 less
			for (int j = y; j; j &= j - 1) {
				less += tree[j];
			}
			ans += (long) less * (n - 1 - y - (i - less));
		}
		return ans;
	}
};













