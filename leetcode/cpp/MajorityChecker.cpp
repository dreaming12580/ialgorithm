#include <unordered_map>
using namespace std;

class MajorityChecker {
private:
	int treeSize = 1;
	int num = 0;
	int segmentTree[65536] = {0};
	unordered_map<int, vector<int>> numindex;

	inline int merge(const int l, const int r) {
		return (l >> 16 > r >> 16 ? l % 65536 : r % 65536) + 
						((l % 65536 == r % 65536 ? (l >> 16) + (r >> 16) : 
						   abs((l >> 16) - (r >> 16))) << 16);
	}


public:
	MajorityChecker(vector<int>& arr) {
		// zkw线段树的查询需要按开区间，故需要在原数组两端各扩充一个元素
		num = arr.size() + 2;
		while (treeSize < num) {
			treeSize <<= 1;
		}
		for (int i = 0; i < arr.size(); ++i) {
			// 所有输入的 arr[i] <= 20000, 数组大小 <= 20000 
			// 用一个 int 的高低 16 位分别表示绝对众数的值和绝对出现次数
			segmentTree[treeSize + i + 1] = (1 << 16) + arr[i];
			numindex[arr[i]].push_back(i);
		}
		for (int i = treeSize - 1; i >= 1; --i) {
			segmentTree[i] = merge(segmentTree[2 * i], segmentTree[2 * i + 1]);
		}
	}

	int query(int left, int right, int threshold) {
		int result = 0;
		for (int s = left + treeSize, t = right + treeSize + 2; s ^ t ^ 1; s >>= 1, t >>= 1) {
			if ( ~s & 1) {
				result = merge(result, segmentTree[s + 1]);
			}
			if (t & 1) {
				result = merge(result, segmentTree[t - 1]);
			}
		}
		if (result >> 16 > 0) {
			auto it_left = lower_bound(numindex[result % 65536].begin(), numindex[result % 65536].end(), left);
			auto it_right = upper_bound(numindex[result % 65536].begin(), numindex[result % 65536].end(), right);
			if (it_right - it_left >= threshold) {
				return result % 65536;
			}
		}
		return -1;
	}
};















