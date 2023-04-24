
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
private:
	const int mod = 1e9 + 7;
public:
	int beautifulBouquet(vector<int>& flowers, int cnt) {
		int ans = 0;
		unordered_map<int, int> count;
		for (int left = 0, right = 0; right < flowers.size(); ++right) {
			++count[flowers[right]];
			while (count[flowers[right]] > cnt) {
				--count[flowers[left]];
				++left;
			}
			ans = ((long long)ans + right - left + 1) % mod;
		}
		return ans;
	}
};

