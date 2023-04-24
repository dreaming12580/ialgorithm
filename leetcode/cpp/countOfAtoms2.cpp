#include <string>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;


class Solution {

public:
	string readAtom(int& pos, string& formula) {
		string atom;
		atom.push_back(formula[pos]);
		pos++; 
		while (pos < formula.size() && islower(formula[pos])) {
			atom.push_back(formula[pos]);
			pos++;
		} 
		return atom;
	}

	int readCnt(int& pos, string& formula) {
		int cnt = 0;
		while (pos < formula.size() && isdigit(formula[pos])) {
			cnt = cnt * 10 + formula[pos] - '0';
			pos++;
		}
		if (cnt == 0) {
			cnt = 1;
		}
		return cnt;
	}


	string countOfAtoms(string formula) {
		vector<tuple<string, int, int>> elementInfo;
		stack<char> parentheses;
		int len = formula.size();
		for (int i = 0; i < len; ++i) {
			char c = formula[i];
			if (isupper(c)) {
				int pos = i;
				string atom = readAtom(pos, formula);
				int cnt = readCnt(pos, formula);
				i = pos + 1;
				elementInfo.push_back({atom, cnt, int(parentheses.size())});
			} else if (c == '(') {
				parentheses.push('(');
			} else if (c == ')') {
				int pos = i + 1;
				int cnt = readCnt(pos, formula);    // pos现在是数字的下一个位置
				i = pos + 1;
				for (int j = elementInfo.size() - 1; j >= 0; --j) {
					if(get<2>(elementInfo[j]) == parentheses.size()) {
						get<1>(elementInfo[j]) *= cnt;
						get<2>(elementInfo[j]) -= 1;
					} else {
						break;
					}
				}
				parentheses.pop();
			}
		}
		map<string, int> dict;
		for (auto info : elementInfo) {
			dict[get<0>(info)] += get<1>(info);
		}

		string res;
		for (auto ele : dict) {
			res += ele.first;
			if (ele.second != 1) {
				res += to_string(ele.second);
			}
		}
		return res;
	}
};

































