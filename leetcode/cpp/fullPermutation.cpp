
#include <iostream>
#include <vector>
#include <set>


using namespace std;

class Solution {
private:


	void dfs(vector<vector<int>>& res, vector<int>& ret, 
			vector<int>& nums, 
			int idx, int k, 
			set<int>& seen) {
		int n = nums.size();
		if (ret.size() == k) {
			res.push_back(ret);
			return;
		}
		if (seen.count(nums[idx])) {
			return;
		}
		ret.push_back(nums[idx]);
		seen.insert(nums[idx]);
		for (int i = 0; i < n; ++i) {
			dfs(res, ret, nums, i, k, seen);
		}
		ret.pop_back();
		seen.erase(nums[idx]);
	}

public:
	vector<vector<int>> compute(vector<int>& nums, int k) {
		int n = nums.size();
		vector<vector<int>> res;
		vector<int> ret;
		set<int> seen;
		for (int i = 0; i < n; ++i) {
			dfs(res, ret, nums, i, k, seen);
		}
		return res;
	}

};


int main() {
	vector<int> v = {1, 5, 3, 6, 7, 2};
	Solution s;
	vector<vector<int>> res = s.compute(v, 3);
	for (auto& ret : res) {
		cout << "item: ";
		for (auto& item : ret) {
			cout << " " << item;
		}
		cout << endl;
	}


}
























