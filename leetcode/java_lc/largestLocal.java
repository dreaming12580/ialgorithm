package java_lc;
import java.util.LinkedList;

class Solution {
	public int[][] largestLocal(int[][] grid) {
		int n = grid.length;
		int [][] res = new int[n - 2][n - 2];					//创建结果数组
		LinkedList<Integer> queue;										// 单调队列
		int value;
		// 循环遍历每一行
		for (int i = 0; i < n; ++i) {
			queue = new LinkedList<>();				// 每一行新建一个单调队列
			// 循环遍历每一列
			for (int j = 0; j < n; ++j) {
				// 单调队列添加候选值
				while (!queue.isEmpty() && grid[i][j] >= grid[i][queue.peekLast()]) {
					queue.pollLast();
				}
				queue.offerLast(j);
				// 滑动窗口达到大小 3 可以处理
				if (j >= 2) {	
					// 获取单调队列中当前行当前滑动窗口中的最大值  即队首索引对应的值
					value = grid[i][queue.peekFirst()];
					// 更新当前行及其前两行该列的最大值
					for (int k = i - 2; k <= i; ++k) {
						// 行必须在结果数组的范围内
						if (k >= 0 && k < n - 2) {
							res[k][j - 2] = Math.max(res[k][j - 2], value);
						}
					}
					if (queue.peekFirst() <= j - 2) {
						queue.pollFirst();
					}
				}

			}
		}
		return res;
	}
}





