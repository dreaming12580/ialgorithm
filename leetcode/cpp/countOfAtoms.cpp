#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

public:
	string countOfAtoms(string formula) {
		int i = 0, n = formula.length();

		auto parseAtom = [&] () -> string {
			string atom;
			atom += formula[i++];
			while (i < n && islower(formula[i])) {
				atom += formula[i++];	//扫描首字母后的小写字母
			}
			return atom;
		};

		auto parseNum = [&] () -> int {
			if (i == n || !isdigit(formula[i])) {
				return 1;	// 不是数字， 视作1
			}
			int num = 0;
			while (i < n && isdigit(formula[i])) {
				num = num * 10 + int(formula[i++] - '0');	// 扫描数字
			}
			return num;
		};

		stack<unordered_map<string, int>> stk;
		stk.push({});
		while (i < n) {
			char ch = formula[i];
			if (ch == '(') {
				++i;
				stk.push({});
			} else if (ch == ')') {
				i++;
				int num = parseNum();	// 括号右侧数字
				auto atomNum = stk.top();
				stk.pop();
				for (auto& [atom, v] : atomNum) {
					stk.top()[atom] += v * num;
				}
			} else {
				string atom = parseAtom();
				int num = parseNum();
				stk.top()[atom] += num;
			}	
		}

		auto& atomNum = stk.top();
		vector<pair<string, int>> pairs;
		for (auto& [atom, v] : atomNum) {
			pairs.emplace_back(atom, v);
		}
		sort(pairs.begin(), pairs.end());

		string ans;
		for (auto& p : pairs) {
			ans += p.first;
			if (p.second > 1) {
				ans += to_string(p.second);
			}
		}
		return ans;
	}
};

































