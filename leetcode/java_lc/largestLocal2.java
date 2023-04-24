package java_lc;
import java.util.LinkedList;

class Solution {
	public int[][] largestLocal(int[][] grid, int h, int w) {
		int n = grid.length;
		// 创建结果数组
		int[][] res = new int[n - h][n - w];
		// 单调队列
		LinkedList<Integer> queue;
		int value;
		for (int i = 0; i < n; ++i) {
			// 每一行新建一个单调队列
			queue = new LinkedList<>();
			for (int j = 0; j < n; ++j) {
				// 单调队列添加候选值
				while (!queue.isEmpty() && grid[i][j] >= grid[i][queue.peekLast()]) {
					queue.pollLast();
				}
				queue.offerLast(j);
				// 滑动窗口达到大小 w 可以处理
				if (j >= w - 1) {
					// 获取单调队列中当前行当前滑动窗口中的最大值  即队首索引对应的值
					value = grid[i][queue.peekFirst()];
					// 更新当前行及其前两行该列的最大值
					for (int k = i - (h - 1); k <= i; ++k) {
						// 行必须在结果数组的范围内
						if (k >= 0 && k < n - h) {
							res[k][j - (w - 1)] = Math.max(res[k][j - (w - 1)], value);
						}
					}
					// 当前最大值位于滑动窗口最左侧，弹出这个最大值
					if (queue.peekFirst() <= j - (w - 1)) {
						queue.pollFirst();
					}
				}
			}
		}
		return res;
	}
}
