#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
private:

	// 在包围圈中
	static constexpr int BLOCKED = -1;
	// 不在包围圈中
	static constexpr int VALID = 0;
	// 无论在不在包围圈中， 但在 n(n - 1)/2 步搜索的过程中经过了 target
	static constexpr int FOUND = 1;

	static constexpr int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	static constexpr int BOUNDARY = 1000000;

public:
	bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
		if (blocked.size() < 2) {
			return true;
		}
		auto hash_fn = [fn = hash<long long>()] (const pair<int, int>& o) -> size_t {
			auto& [x, y] = o;
			return fn((long long)x << 20 | y);
		};
		unordered_set<pair<int, int>, decltype(hash_fn)> hash_blocked(0, hash_fn);
		for (const auto& pos : blocked) {
			hash_blocked.emplace(pos[0], pos[1]);
		} 






	}





};











