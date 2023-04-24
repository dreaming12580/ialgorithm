#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int rectangleArea(vector<vector<int>>& rectangles) {
		int n = rectangles.size();
		vector<int> hbound;
		for (const auto& rect : rectangles) {
			// 下边界
			hbound.push_back(rect[1]);
			// 上边界
			hbound.push_back(rect[3]);
		}
		sort(hbound.begin(), hbound.end());
		hbound.erase(unique(hbound.begin(), hbound.end()), hbound.end());
		int m = hbound.size();
		// 【思路与算法部分】 的 length 数组不需要显式地存储下来
		// length[i] 可以通过 hbound[i + 1] - hbound[i] 得到
		vector<int> seg(m - 1);

		vector<tuple<int, int, int>> sweep;
		for (int i = 0; i < n; ++i) {
			// 左边界
			sweep.emplace_back(rectangles[i][0], i, 1);
			// 右边界
			sweep.emplace_back(rectangles[i][2], i, -1);
		}
		sort(sweep.begin(), sweep.end());

		long long ans = 0;
		for (int i = 0; i < sweep.size(); ++i) {
			int j = i;
			while (j + 1 < sweep.size() && get<0>(sweep[i]) == get<0>(sweep[j + 1])) {
				++j;
			}
			if (j + 1 == sweep.size()) {
				break;
			}
			// i 到 j 的横坐标是相同的， [i, j]与 j + 1的横坐标不同
			// 一次性地处理掉一批横坐标相同的左右边界
			for (int k = i; k <= j; ++k) {
				auto&& [_, idx, diff] = sweep[k];
				int lower = rectangles[idx][1], high = rectangles[idx][3];
				for (int x = 0; x < m - 1; ++x) {
					if (lower <= hbound[x] && hbound[x + 1] <= high) {
						seg[x] += diff;
					}
				}
			}

			// 统计 y 坐标上的 覆盖范围
			int cover = 0;
			for (int k = 0; k < m - 1; ++k) {
				if (seg[k] > 0) {
					cover += (hbound[k + 1] - hbound[k]);
				}
			}
			ans += static_cast<long long>(cover) * (get<0>(sweep[j + 1]) - get<0>(sweep[j]));
			i = j;
		}
		return ans % static_cast<int>(1e9 + 7);
	}

};













