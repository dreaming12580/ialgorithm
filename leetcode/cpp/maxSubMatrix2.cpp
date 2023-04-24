

#include <vector>

using namespace std;

class Solution {

public:

    vector<int> maxSubMatrix2(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        // 枚举上边界
        for (int i = 0; i < m; ++i) {
            vector<int> sum(n);
            // 枚举下边界
            for (int j = i; j < m; ++j) {
                for (int c = 0; c < n; ++c) {
                    //
                    sum[c] += matrix[j][c];
                }



            }




        }







    }







};



























