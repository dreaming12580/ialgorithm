#include <string>
#include <iostream>



using namespace std;


class Solution {

public:
	string smallestSubsequence(string s, int k, char letter, int repetition) {
		int n = s.size();
		int cnt = 0; // 后面还未扫描到的 letter的数量
		// 统计 letter出现的数量
		for (int i = 0; i < n; ++i) {
			if (s[i] == letter) {
				++cnt;
			}
		}
		
		int toErase = n - k;	// 要删去 n - k 个元素
		string res;				// 答案
		int p = 0;				//目前为止 letter 已扫描了的次数
		for (int i = 0; i < n; ++i) {
			while (toErase && res.size() && s[i] < res.back()) {	// 删去逆序的字母
				if (res.back() == letter) {
					if (repetition > p - 1 + cnt) {		// 后面的 letter 不够凑成 repetition 个 letter
						break;
					}
					--p;	// 可以删除
				}
				res.pop_back();
				--toErase;	// 删去一个
			}
			if (s[i] == letter) {
				++p;		// 前面增加
				--cnt;		// 后面减少
			}
			res += s[i];
		}
		// 是因为逆序字母可能不够的原因， 会漏删一些元素， 现在检查补上
		while (res.size() > k) {
			if (res.back() == letter) {
				--p;
			}
			res.pop_back();
		}
		// 因为前面的元素可能比 letter更小， 所以要检查一下补上 letter
		for (int i = k - 1; i >= 0; --i) {
			// 这是为了保证 letter 个数足够， 但 letter不够小， 所以得从后往前补。
			if (p < repetition && res[i] != letter) {
				res[i] = letter;
				++p;
			}
		}
		return res;
	}
};































