

class Solution {
public:
	unordered_map<char, int> m1, m2;
	
	bool isItPossible(string word1, string word2) {
		// 哈希表计数
		for (char &ch : word1) {
			m1[ch]++;
		}
		for (char &ch : word2) {
			m2[ch]++;
		}
		int len1 = m1.size(), len2 = m2.size(); 
		// 如果相差 > 2, 只换一个字母是不可能相等的
		if (abs(len1 - len2) > 2) {
			return false;
		}
		for (const auto& [c1, fre1] : m1) {
			for (const auto& [c2, fre2] : m2) {
				if (c1 == c2) {
					// c1 与 c2交换对 len 不影响
					if (len1 == len2) {
						return true;
					}
				} else {
					// 分类讨论的话情况太多， 不足直接计算变化量， 也不需要考虑什么交换方向
					// 要将c1 和 c2交换， 如果 c1(换走的)在 s1中只有一个， cnt--, 
					// 但是如果换过来的 c2不存在， 又会多一种， cnt++
					// 相对于 s2 是同样的， 如果换走的 c2 只有一个， cnt--
					if ( (len1 - (fre1 == 1) + (!m1.count(c2))) == 
					     (len2 - (fre2 == 1) + (!m2.count(c1)))) {
						return true;
					}
				}
			}
		}
		return false;
	}
};












