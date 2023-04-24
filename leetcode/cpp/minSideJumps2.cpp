
// d[i][j] 表示青蛙到达 i 号点的 j 号跑道时所需要的最少侧跳次数


class Solution {
	static constexpr int inf = 0x3f3f3f3f;

public:
	int minSideJumps(vector<int> &obstacles) {
		int n = obstacles.size() - 1;
		// d[j] 表示青蛙到达当前第 i 处 位置 j 号跑道所需要的最少侧跳次数
		vector<int> d = {1, 0, 1};
		for (int i = 1; i <= n; ++i) {
			int minCnt = inf;
			for (int j = 0; j < 3; ++j) {
				if (j == obstacles[i] - 1) {
					d[j] = inf;
				} else {
					minCnt = min(minCnt, d[j]);
				}
			}
			for (int j = 0; j < 3; ++j) {
				if (j == obstacles[i] - 1) {
					continue;
				}
				d[j] = min(d[j], minCnt + 1);
			}
		}

	}





};












