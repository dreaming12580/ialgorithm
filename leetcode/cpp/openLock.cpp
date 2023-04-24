#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;


class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		unordered_set<string> dead(deadends.begin(), deadends.end());
		if (dead.count("0000")) {
			return -1;
		}
		if (target == "0000") {
			return 0;
		}
		auto num_prev = [](char x) -> char {
			return (x == '0' ? '9' : x - 1);
		};
		auto num_next = [](char x) -> char {
			return (x == '9' ? '0' : x + 1);
		};
		// 枚举 status 通过一次旋转得到的数字
		auto get = [&](string& status) -> vector<string> {
			vector<string> ret;
			for (int i = 0; i < 4; ++i) {
				char num = status[i];
				status[i] = num_prev(num);
				ret.push_back(status);
				status[i] = num_next(num);
				ret.push_back(status);
				status[i] = num;
			}
			return ret;
		};
		queue<pair<string, int>> q;
		q.emplace("0000", 0);
		unordered_set<string> seen = {"0000"};

		while (!q.empty()) {
			auto [status, step] = q.front();
			q.pop();
			for (auto&& next_status : get(status)) {
				if (!seen.count(next_status) && !dead.count(next_status)) {
					if (next_status == target) {
						return step + 1;
					}
					q.emplace(next_status, step + 1);
					seen.insert(move(next_status));
				}
			}
		}
		return -1;
	}
};



