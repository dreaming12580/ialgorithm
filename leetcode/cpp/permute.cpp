#include <vector>

using namespace std;

class Solution {
private:

    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len) {
        // 所有数据都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归下一个数
            backtrack(res, output, first+1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }


public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};




