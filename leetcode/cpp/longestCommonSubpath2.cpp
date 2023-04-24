#include <vector>
#include <random>
#include <algorithm>
#include <unordered_set>


using namespace std;


class Solution {

private:
	static constexpr int mod1 = 1e9 + 7;
	static constexpr int mod2 = 1e9 + 9;

	struct pairhash {
		size_t operator() (const pair<int, int>& p) const {
			auto fn = hash<int>();
			return (fn(p.first) << 16) ^ fn(p.second);
		}
	};

	using LL = long long;

public:
	int longestCommonSubpath(int n, vector<vector<int>>& paths) {
		mt19937 gen{random_device{}()};
		auto dis = uniform_int_distribution<int>(1e6, 1e7);
		int base1 = dis(gen);
		int base2 = dis(gen);

		int m = paths.size();
		// 确定二分查找的上下界
		int left = 1, right = min_element(paths.begin(), paths.end(), 
				[](const auto& p1, const auto& p2) {
					return p1.size() < p2.size();
				})->size();
		int ans = 0;
		while (left <= right) {
			int len = (left + right) /  2;
			// 预处理 mult1 = base1 ^ len, mult2 = base2 ^ len;
			int mult1 = 1, mult2 = 1;
			for (int i = 1; i <= len; ++i) {
				mult1 = (LL)mult1 * base1 % mod1;
				mult2 = (LL)mult2 * base2 % mod2;
			}

			unordered_set<pair<int, int>, pairhash> s;
			bool check = true;

			for (int i = 0; i < m; ++i) {
				int hash1 = 0, hash2 = 0;
				// 计算首个长度为len的子数组的哈希值
				for (int j = 0; j < len; ++j) {
					hash1 = ((LL)hash1 * base1 + paths[i][j]) % mod1;
					hash2 = ((LL)hash2 * base2 + paths[i][j]) % mod2;
				}





			}







		}



	}




};























