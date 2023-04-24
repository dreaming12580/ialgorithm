




class Solution {

public:
	int calculate(string &s) {
		int i = 0;
		return parseExpr(s, i);
	}

	int parseExpr(string& s, int& i) {
		vector<int> nums;
		char op = '+';
		for (; i < s.length() && op != ')'; ++i) {
			if (s[i] == ' ') {
				continue;
			}
			int n;
			if (s[i] == '(') {
				n = parseExpr(s, ++i);
			} else {
				n = parseNum(s, i);
			}
			switch(op) {
				case '+': nums.push_back(n); break;
				case '-': nums.push_back(-n); break;
				case '*': nums.back() *= n; break;
				case '/': nums.back() /= n; break;
			}
			op = s[i];
		}
		int ret = 0;
		for (int num : nums) {
			ret += num;
		}
		return ret;
	}

	int parseNum(string& s, int& i) {
		int num = 0;
		while (s[i] >= '0' && s[i] <= '9') {
			num = num * 10 + s[i] - '0';
			++i;
		}
		return num;
	}
};









