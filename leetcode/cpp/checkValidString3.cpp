#include <string>

using namespace std;


class Solution {
public:
	bool checkValidString(string s) {
		int min_count = 0, max_count = 0;
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			char c = s[i];
			if (c == '(') {
				++min_count;
				++max_count;
			} else if (c == ')') {
				min_count = max(min_count - 1, 0);
				--max_count;
				if (max_count < 0) {
					return false;
				}
			} else {
				min_count = max(min_count - 1, 0);
				++max_count;
			}
		}
		return min_count == 0;
	}
};













