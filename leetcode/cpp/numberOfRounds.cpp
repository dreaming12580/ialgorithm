

#include <string>

using namespace std;


class Solution {
public:
	int numberOfRounds(string startTime, string finishTime) {
		// 转化为分钟
		int t0 = 60 * stoi(startTime.substr(0, 2)) + stoi(startTime.substr(3, 2));
		int t1 = 60 * stoi(finishTime.substr(0, 2)) + stoi(finishTime.substr(3, 2));
		if (t1 < t0) {
			// 此时 finishTime 为第二天
			t1 += 1440;
		}
		// 第一个小于等于 finishTime 的完整对局的结束时间
		t1 = t1 / 15 * 15;
		t0 = (t0 + 14) / 15 * 15;
		return (t1 - t0) / 15;


	}
};





























