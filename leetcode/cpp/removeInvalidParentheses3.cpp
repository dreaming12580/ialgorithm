#include <vector>
#include <string>
#include <unordered_set>


using namespace std;

class Solution {

public:
	bool checkValid(const string& str, int lmask, vector<int>& left, int rmask, vector<int>& right) {
		int pos1 = 0, pos2 = 0, cnt = 0;
		for (int i = 0; i < str.size(); ++i) {
			if (pos1 < left.size() && i == left[pos1]) {
				// 第 i 个位置为 '(', 并且状态子集lmask 没有将该位置去掉， 则++cnt;
				if (!(lmask & (1 << pos1))) {
					++cnt;
				}
				++pos1;
			} else if (pos2 < right.size() && i == right[pos2]) {
				// 第 i 个位置为 ')', 并且状态子集rmask 没有将该位置去掉， 则--cnt;
				if (!(rmask & (1 << pos2))) {
					--cnt;
					if (cnt < 0) {
						return false;
					}
				} 
				++pos2;
			}
		}
		retun cnt == 0;
	}

	string recoverStr(const string& str, int lmask, vector<int>& left, int rmask, vector<int>& right) {
		string ans;
		int pos1 = 0, pos2 = 0;
		for (int i = 0; i < str.size(); ++i) {
			if (pos1 < left.size() && i == left[pos1]) {
				if (!(lmask & (1 << pos1))) {
					ans.push_back(str[i]);
				}
				++pos1;
			} else if (pos2 < right.size() && i == right[pos2]) {
				if (!(rmask & (1 << pos2))) {
					ans.push_back(str[i]);
				}
				++pos2;
			} else {
				ans.push_back(str[i]);
			}
		}
		return ans;
	}


	vector<string> removeInvalidParentheses(string s) {
		int lremove = 0, rremove = 0;
		vector<int> left, right;
		vector<string> ans;
		unordered_set<string> cnt;

		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(') {
				left.push_back(i);
				++lremove;
			} else if (s[i] == ')') {
				right.push_back(i);
				if (lremove == 0) {
					++rremove;
				} else {
					--lremove;
				}
			}
		}

		int m = left.size(), n = right.size();
		vector<int> maskArr1, maskArr2;
		for (int i = 0; i < (1 << m); ++i) {
			if (__builtin_popcount(i) != lremove) {
				continue;
			}
			maskArr1.push_back(i);
		}
		for (int j = 0; j < (1 << n); ++j) {
			if (__builtin_popcount(j) != rremove) {
				continue;
			}
			maskArr2.push_back(j);
		}

		for (auto mask1 : maskArr1) {
			for (auto mask2 : maskArr2) {
				if (checkValid(s, mask1, left, mask2, right)) {
					cnt.insert(recoverStr(s, mask1, left, mask2, right));
				}
			}
		}
		for (auto v : cnt) {
			ans.emplace_back(v);
		}
		return ans;
	}





};





























