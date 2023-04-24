


#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> cnt;
        for (auto& widths : wall) {
            int n = widths.size();
            int sum = 0;
            for (int i = 0; i < n - 1; i++) {
                sum += widths[i];
                cnt[sum]++;
            }
        }
        int max_cnt = 0;
        for (auto& [_, c] : cnt) {
            max_cnt = max(max_cnt, c);
        }
        return wall.size() - max_cnt;
    }











};















