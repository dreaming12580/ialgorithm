
#include <vector>
#include <map>


using namespace std;


class Solution {
public:
	map<vector<int>, int> memo;

	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		int n = price.size();

		// 过滤不需要计算的大礼包， 只保留需要计算的大礼包
		vector<vector<int>> filterSpecial;
		for (auto& sp : special) {
			int totalCount = 0, totalPrice = 0;
			for (int i = 0; i < n; ++i) {
				totalCount += sp[i];
				totalPrice += sp[i] * price[i];
			}
			if (totalCount > 0 && totalPrice > sp[n]) {
				filterSpecial.emplace_back(sp);
			}
		}

		return dfs(price, needs, filterSpecial, n);
	}

	// 记忆化搜索计算满足购物清单所需花费的最低价格
	int dfs(const vector<int>& price, vector<int> curNeeds, vector<vector<int>>& filterSpecial, int n) {
		if (!memo.count(curNeeds)) {
			int minPrice = 0;
			for (int i = 0; i < n; ++i) {
				// 不购买任何大礼包， 原价购买购物清单中的所有物品
				minPrice += curNeeds[i] * price[i];
			}
			for (auto& curSpecial : filterSpecial) {
				int specialPrice = curSpecial[n];
				vector<int> nxtNeeds;
				for (int i = 0; i < n; ++i) {
					// 不能购买超出购物清单指定数量的物品
					if (curSpecial[i] > curNeeds[i]) {
						break;
					}
					nxtNeeds.emplace_back(curNeeds[i] - curSpecial[i]);
				}
				// 大礼包可以购买
				if (nxtNeeds.size() == n) {
					minPrice = min(minPrice, dfs(price, nxtNeeds, filterSpecial, n) + specialPrice);
				}
			}
			memo[curNeeds] = minPrice;
		}
		return memo[curNeeds];
	}
};












