

#include <string>
#include <vector>



using namespace std;

class Solution {
public:
	string maximumNumber(string num, vector<int>& change) {
		int n = num.size();
		for (int i = 0; i < n; ++i) {
			// 寻找第一个突变后数值更大的位作为左边界
			if (change[num[i] - '0'] > num[i] - '0') {
				// 尝试更新右边界
				while (i < n && change[num[i] - '0'] >= num[i] - '0') {
					num[i] = '0' + change[num[i] - '0'];
					++i;
				}
				break;
			}
		}
		return num;
	}













};




















