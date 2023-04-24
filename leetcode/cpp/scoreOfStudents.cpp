#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	int scoreOfStudents(string s, vector<int>& answers) {
		// Step 1: 统计所有学生答案
		// 所有学生答案都在[0, 1000], 因此开一个差不多大小的空间即可
		vector<int> count(1024);
		for (auto p : answers) {
			count[p]++;
		}
		// Step 2: 计算正确结果
		stack<int> st;
		st.push(s[0] - '0');	// 第一个元素入栈
		for (int i = 1; i < s.length(); i += 2) {
			if (s[i] == '+') {
				st.push(s[i + 1] - '0');
			} else {
				// 乘法运算， 直接做
				st.top() *= (s[i + 1] - '0');
			}
		}
		// 弹栈， 计算所有加法运算
		int right = 0;
		while (!st.empty()) {
			right += st.top();
			st.pop();
		}

		// 正确得分 = 5 * 正确人数
		int ans = 5 * count[right];

		// Step 3: 枚举所有可能结果
		// 开空间， dp为 n * n 的数组， 每一项为一个集合
		int len = s.length();
		vector<vector<unordered_set<int>>> dp(len + 2, vector<unordered_set<int>>(len + 2));
		// 初始化， 对应 i == j的情况， 能组成的值为其本身
		for (int j = 0; j < len; j += 2) {
			dp[j][j].insert(s[j] - '0');
		}
		// 枚举步伐， 不断增大， 即 step = j - i
		for (int step = 2; step < len; step += 2) {
			// 枚举开始位置 i
			for (int i = 0; i + step < len; i += 2) {
				// 枚举左半部分长度 t
				for (int t = 0; t < step; t += 2) {
					// x 是左半部分所有可能值
					// y 是右半部分所有可能值
					for (auto x : dp[i][i + t]) {
						for (auto y : dp[i + t + 2][i + step]) {
							// 根据中间连接符是 +/*, 来计算连接后的值
							if (s[i + t + 1] == '+') {
								// 因为学生猜想结果均在 [0, 1000], 因此超限的值可以直接忽略。
								if (x + y <= 1000) {
									dp[i][i + step].insert(x + y);
								}
							} else {
								if (x * y <= 1000) {
									dp[i][i + step].insert(x * y);
								}
							}
						}
					}
				}
			}
		}
		// Step 4: 统计顺序错误同学得分
		for (auto p : dp[0][len - 1]) [
			// 只有错误答案需要统计， 防止二次统计正确同学
			if (p != right) {
				ans += 2 * count[p];
			}
		]
		return ans;
	}
};



























