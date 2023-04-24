#include <vector>
#include <string>

using namespace std;



class Solution {
public:
	string minNumber(vector<int>& nums) {
		vector<string> strs;
		for (int i = 0; i < nums.size(); ++i) {
			strs.push_back(to_string(nums[i]));
		}
		quickSort(strs, 0, strs.size() - 1);
		string res;
		for (string s : strs) {
			res.append(s);
		}
		return res;
	}

private:
	void quickSort(vector<string>& strs, int l, int r) {
		if (l >= r) {
			return;
		}
		int i = l, j = r;
		while (i < j) {
			while (strs[j] + strs[l] >= strs[l] + strs[j] && i < j) {
				--j;
			}
			while (strs[i] + strs[l] <= strs[l] + strs[i] && i < j) {
				++i;
			}
			swap(strs[i], strs[j]);
			quickSort(strs, l, i - 1);
			quickSort(strs, i + 1, r);
		}
	}
};













