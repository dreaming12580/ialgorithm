




class Solution {
public:
	vector<string> braceExpansionII(string expression) {
		vector<char> op;
		vector<set<string>> stk;

		// 弹出栈顶运算符，并进行计算
		auto ope = [&]() {
			int l = stk.size() - 2, r = stk.size() - 1;
			// + 是求并集
			if (op.back() == '+') {
				stk[l].merge(stk[r]);
			} else {
				// * 是求两个集合栈的笛卡尔积
				set<string> tmp;
				for (auto &left : stk[l]) {
					for (auto &right : stk[r]) {
						tmp.insert(left + right);
					}
				}
				stk[l] = move(tmp);
			}
			op.pop_back();
			stk.pop_back();
		};

		for (int i = 0; i < expression.size(); i++) { 
			if (expression[i] == ',') {
				// 不断地弹出栈顶运算符， 直到栈为空或者栈顶不为乘号
				while (op.size() && op.back() == '*') {
					ope();
				}
				op.push_back('+');
			} else if (expression[i] == '{') {
				// 首先判断是否需要添加乘号， 再将 { 添加到运算符栈中
				if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1]))) {
					op.push_back('*');
				}
				op.push_back('{');
			} else if (expression[i] == '}') {
				// 不断地弹出栈顶运算符， 直到栈顶为 {
				while (op.size() && op.back() != '{') {
					ope();
				}
				op.pop_back();
			} else {
				// 首先判断是否需要添加乘号， 再将新构造的集合添加到集合栈中
				if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1]))) {
					op.push_back('*');
				}
				stk.push_back({string(1, expression[i])});
			}
		}

		while (op.size()) {
			ope();
		}
		return {stk.back().begin(), stk.back().end()};
	}
};




