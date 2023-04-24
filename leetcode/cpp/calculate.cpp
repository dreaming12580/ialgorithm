



class Solution {


public:
	int calculate(string s) {
		stack<int> ops;
		ops.push(1);
		int sign = 1;

		int ret = 0;
		int n = s.length();
		for (int i = 0; i < n; ++i) {
			if (s[i] == ' ') {
				continue;
			} else if (s[i] == '+') {
				sign = ops.top();
			} else if (s[i] == '-') {
				sign = -ops.top();
			} else if (s[i] == '(') {
				ops.push(sign);
			} else if (s[i] == ')') {
				ops.pop();
			} else {
				long num = 0;
				while (i < n && s[i] >= '0' && s[i] <= '9') {
					num = num * 10 + s[i] - '0';
					++i;
				}
				ret += sign * num;
				--i;
			}
		}
		return ret;
	}
};









