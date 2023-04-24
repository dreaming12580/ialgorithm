
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
	vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
		// 计算每个位置对应的颜色和改变量并用哈希表存储
		unordered_map<int, long long> color;
		for (auto&& segment : segments) {
			int l = segment[0];
			int r = segment[1];
			int c = segment[2];
			if (!color.count(l)) {
				color[l] = 0;
			}
			color[l] += c;
			if (!color.count(r)) {
				color[r] = 0;
			}
			color[r] -= c;
		}
		// 将哈希表转化为数组并按数轴坐标升序排序
		vector<pair<int, long long>> axis;
		for (auto&& [k, v] : color) {
			axis.emplace_back(k, v);
		}
		sort(axis.begin(), axis.end());
		// 对数组求前缀和计算对应颜色和
		int n = axis.size();
		for (int i = 1; i < n; ++i) {
			axis[i].second += axis[i - 1].second;
		}
		// 遍历数组生成最终绘画结果
		vector<vector<long long>> res;
		for (int i = 0; i < n - 1; ++i) {
			if (axis[i].second) {
				res.emplace_back(vector<long long> {
					axis[i].first, axis[i + 1].frist, axis[i].second
				});
			}
		}
		return res;
	}
};






























