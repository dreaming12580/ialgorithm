




class Solution {
private:
	static constexpr int kWidth = 5;
	static constexpr int kWidthMask = (1 << kWidth) - 1;

public:
	int maxHappyGroups(int batchSize, vector<int>& groups) {
		// 用于存储每个余数对应的数量， 方便构建初始状态
		vector<int> cnt(batchSize);
		for (int x : groups) {
			// 统计所有余数
			++cnt[x % batchSize];
		}

		// 起始状态
		long long start = 0;
		// 构建初始的统计值
		for (int i = batchSize - 1; i >= 1; --i) {
			// 左移将低位变为 0， 已经加入的信息被移动到高位从而被保留
			// 而与操作只会影响低位
			start = (start << kWidth) | cnt[i];
		}

		// 用于记录当前状态 (每个余数的剩余组数 的组合) 对应的返回值， 减少递归次数 (记忆搜索)
		unordered_map<long long, int> memo;

		// lambda 表达式 (匿名函数)， 返回值是 int, 输入是 long long, & 表示引用参数
		// 用于递归获取最终结果
		function<int(long long)> dfs = [&] (long long mask) -> int {
			if (mask == 0) {
				return 0;
			}
			if (memo.count(mask)) {
				return memo[mask];
			}

			// 开始处理


			// 首先获取当前状态下的总顾客(余)数
			int total = 0;
			// 遍历所有可能余数
			for (int i = 1; i < batchSize; ++i) {
				// 获取每个余数的对应组数
				// 先将对应位置右移到低 5 位，再与0b11111获取对应数字
				int amount = ((mask >> ((i - 1) * kWidth)) & kWidthMask);
				total += i * amount;
			}

			// 获得最优解
			int best = 0; 
			// 枚举所有状态， 因为是递归， 所以每次递归都会在循环中遍历所有可能的情况
			// 此处应抽象为倒序， 因为被枚举的值被认为是当前状态下最后一组购买的顾客
			// 因此最深的递归对应的那一组实际上是第一组购买的顾客
			for (int i = 1; i < batchSize; ++i) {
				// 获取对应值
				int amount = ((mask >> ((i - 1) * kWidth)) & kWidthMask);
				
				// 该选项还有剩余 (这条路能往下走)
				if (amount > 0) {

					// 递归获取 (最后一组之前的) 结果
					// 递归输入的参数是对应值 -1 后的 mask
					// 原理是将 1 移动到相应的位置， 再用 mask 减去即可
					int result = dfs(mask - (1LL << ((i - 1) * kWidth)));
					if ((total - i) % batchSize == 0) {
						++result;
					}
					best = max(best, result);
				}
			}
			return memo[mask] = best;
		};

		return dfs(start) + cnt[0];
	}
};













