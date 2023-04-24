#include <string>


using namespace std;


class Solution {
public:
	bool checkValidString(string s) {
		stack<int> left_st;
		stack<int> asterisk_st;
		int n = s.size();

		for (int i = 0; i < n; ++i) {
			char c = s[i];
			if (c == '(') {
				left_st.push(i);
			} else if (c == '*') {
				asterisk_st.push(i);
			} else {
				if (!left_st.empty()) {
					left_st.pop();
				} else if (!asterisk_st.empty()) {
					asterisk_st.pop();
				} else {
					return false;
				}
			}
		}

		while (!left_st.empty() && !asterisk_st.empty()) {
			int left_idx = left_st.top();
			left_st.pop();
			int asterisk_idx = asterisk_st.top();
			asterisk_st.pop();
			if (left_idx > asterisk_idx) {
				return false;
			}
		}
		return left_st.empty();
	}
};












