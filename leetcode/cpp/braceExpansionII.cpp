


class Solution {
private:
	string expression;
	int idx;

	// item -> letter / { expr }
	set<string> item() { 
		set<string> ret;
		if (expression[idx] == '{') {
			idx++;
			ret = expr();
		} else {
			ret = {string(1, expression[idx])};
		}
		++idx;
		return move(ret);
	}

	// term -> item | item term
	set<string> term() {
		// 初始化空集合， 与之后的求解结果求笛卡尔积
		set<string> ret = {""};
		// item 的开头是 { 或小写字母， 只有符合时才继续匹配
		while (idx < expression.size() && (expression[idx] == '{' || isalpha(expression[idx]))) {
			auto sub = item();
			set<string> tmp;
			for (auto &left : ret) {
				for (auto &right : sub) {
					tmp.insert(left + right);
				}
			}
			ret = move(tmp);
		}
		return move(ret);
	}

	// expr -> term | term, expr
	set<string> expr() {
		set<string> ret;
		while (true) {
			// 与 term() 求解结果求并集
			ret.merge(term());
			// 如果匹配到逗号则继续， 否则结束匹配
			if (idx < expression.size() && expression[idx] == ',') {
				idx++;
				continue;
			} else {
				break;
			}
		}
		return move(ret);
	}

public:
	vector<string> braceExpansionII(string expression) {
		this->expression = expression;
		this->idx = 0;
		auto ret = expr();
		return {ret.begin(), ret.end()};
	}
};




