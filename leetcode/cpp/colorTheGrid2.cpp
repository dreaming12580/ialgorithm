#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
private:
	static constexpr int mod =  1e9 + 7;

public:
	int colorTheGrid(int m, int n) {
		// 哈希映射 valid 存储所有满足要求的对一行进行涂色的方案
		// 键表示 mask, 值表示 mask的三进制串 (以列表的形式存储)
		unordered_map<int, vector<int>> valid;

		// 在 [0, 3^m) 范围内枚举满足要求的 mask 
		int mask_end = pow(3, m);
		for (int mask = 0; mask < mask_end; ++mask) {
			vector<int> color;
			int mm = mask; 
			for (int i = 0; i < m; ++i) {
				color.push_back(mm % 3);
				mm /= 3;
			}
			bool check = true; 
			for (int i = 0; i < m - 1; ++i) {
				if (color[i] == color[i + 1]) {
					check = false;
					break;
				}
			}
			if (check) {
				valid[mask] = move(color);
			}
		}

		// 预处理所有的(mask1, mask2) 二元组， 
		// 满足mask1 和 mask2 作为相邻行时， 同一列上两个格子的颜色不同
		unordered_map<int, vector<int>> adjacent;
		for (const auto& [mask1, color1] : valid) {
			for (const auto& [mask2, color2] : valid) {
				bool check = true;
				for (int i = 0; i < m; ++i) {
					if (color1[i] == color2[i]) {
						check = false;
						break;
					}
				}
				if (check) {
					adjacent[mask1].push_back(mask2);
				}
			}
		}
		vector<int> f(mask_end);
		for (const auto& [mask, _] : valid) {
			f[mask] = 1;
		}
		for (int i = 1; i < n; ++i) {
			vector<int> g(mask_end);
			for (const auto& [mask1, _] : valid) {
				for (int mask2 : adjacent[mask1]) {
					g[mask2] = (g[mask2] + f[mask1]) % mod;
				}
			}
			f = move(g);
		}

		int ans = 0;
		for (int num : f) {
			ans = (ans + num) % mod;
		}
		return ans;
	}
};

























