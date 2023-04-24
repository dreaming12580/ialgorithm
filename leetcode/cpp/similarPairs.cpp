



class Solution {
public:
	int similarPairs(vector<string>& words) {
		int ans = 0;
		unordered_map<int, int> cnt;
		for (auto& word : words) {
			int mask = 0;
			for (auto& c : word) {
				mask | = 1 << (c - 'a');
			}
			ans += cnt[mask];
			cnt[mask] += 1;
		}
		return ans;
	}
};















