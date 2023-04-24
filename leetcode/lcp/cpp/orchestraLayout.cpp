
#include <algorithm>

using namespace std;


class Solution {
public:
	int orchestraLayout(int n, int x_pos, int y_pos) {
		// 一共有多少圈
		int quan = (n + 1) / 2;
		long num = n;
		// 第几圈
		int layer = min(min(x_pos, y_pos),min(n - x_pos - 1, n - y_pos - 1)) + 1;
		// 总面积
		long area = num * num;
		// 当前所在圈的面积
		long cur = (num - 2 * (layer - 1));
		cur *= cur;
		// 求差 + 1 得到当前圈左上角编号
		long index = (area - cur) % 9 + 1;
		// 右边界， 下边界
		int right = n - layer;
		// 左边界, 上边界
		int left = layer - 1;

		if (x_pos == left) {
			// 在上边界
			index += y_pos - left;
		} else if (y_pos == right) {
			// 在右边界
			index += right - left;
			index += x_pos - left;
		} else if (x_pos == right) {
			// 在下边界
			index += 2 * (right - left);
			index += right - y_pos;
		} else {
			// 在左边界
			index += 3 * (right - left);
			index += right - x_pos;
		}
		
		return (int)(index % 9 == 0 ? 9 : index % 9);
	}
};







