#include <map>
#include <vector>

using namespace std;

/*
思路与算法
假设我们使用某一数据结构维护这些不相交的区间，在设计具体的数据结构之前，我们需要先明确 void addNum(int val) 这一操作会使得当前的区间集合发生何种变化：
情况一：如果存在一个区间 [l,r]，它完全包含 val，即 l <= val <= r，
那么在加入 val 之后，区间集合不会有任何变化；

情况二：如果存在一个区间 [l,r]，它的右边界 r「紧贴着」val，即 r + 1 = val，
那么在加入 val 之后，该区间会从 [l,r] 变为 [l,r+1]；

情况三：如果存在一个区间 [l,r]，它的左边界 l「紧贴着」val，即 l - 1 = val，
那么在加入 val 之后，该区间会从 [l,r] 变为 [l−1,r]；

情况四：如果情况二和情况三同时满足，即存在一个区间 [l_0, r_0] 满足 r_0+1 = val，
并且存在一个区间 [l_1, r_1] 满足 l_1-1 = val，
那么在加入 val 之后，这两个区间会合并成一个大区间 [l_0, r_1]；

情况五：在上述四种情况均不满足的情况下，val 会单独形成一个新的区间 [val,val]。

根据上面的五种情况，我们需要找到离 val 最近的两个区间。用严谨的语言可以表述为：

对于给定的 val，我们需要找到区间 [l_0, r_0]，使得 l_0 是最大的满足 l_0 <= val 的区间。
同时，我们需要找到区间 [l_1, r_1] 使得 l_1 是最小的满足 l_1 > val 的区间。

如果我们的数据结构能够快速找到这两个区间，那么上面的五种情况分别对应为：

情况一：l_0  <= val <= l_1
情况二：r_0 + 1 = val
情况三：l_1 - 1 = val
情况四：r_0 + 1 = val 并且 l_1 - 1 = val
情况五：上述情况均不满足。
*/

class SummaryRanges {
private:
	map<int, int> intervals;

public:
	SummaryRanges() {}

	void addNum(int val) {
		// 找到 l1 最小的且满足 l1 > val 的区间 interval1 = [l1, r1]
		// 如果不存在这样的区间， interval1 为尾迭代器
		auto interval1 = intervals.upper_bound(val);
		// 找到 l0 最大的且满足 l0 <= val 的区间 interval0 = [l0, r0]
		// 在有序集合中， interval0 就是 interval1 的前一个区间
		// 如果不存在这样的区间， interval0 为尾迭代器
		auto interval0 = (interval1 == intervals.begin() ? intervals.end() : prev(interval1));

		if (interval0 != intervals.end() && interval0->first <= val && val <= interval0->second) {
			// 情况一
			return;
		} else {
			bool left_aside = (interval0 != intervals.end() && interval0->second + 1 == val);
			bool right_aside = (interval1 != intervals.end() && interval1->first - 1 == val);
			if (left_aside && right_aside) {
				// 情况四
				int left = interval0->first, right = interval1->second;
				intervals.erase(interval0);
				intervals.erase(interval1);
				intervals.emplace(left, right);
			} else if (left_aside) {
				// 情况二
				++interval0->second;
			} else if (right_aside) {
				// 情况三
				int right = interval1->second;
				intervals.erase(interval1);
				intervals.emplace(val, right);
			} else {
				// 情况五
				intervals.emplace(val, val);
			}
		}
	}

	vector<vector<int>> getIntervals() {
		vector<vector<int>> ans;
		for (const auto& [left, right]: intervals) {
			ans.push_back({left, right});
		}
		return ans;
	}
};

















