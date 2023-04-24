class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        cout << "m:" << m << ", n:" << n << endl;
        vector<int> res;
        unordered_map<int, unordered_map<int, bool>> hash;
        
        for (int i = 0; i < m; ++i) {
            int dest_j = 0;
            int dest_min = INT_MAX;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] < dest_min) {
                    dest_min = matrix[i][j];
                    dest_j = j;
                }
            }

            cout << "i:" << i << ", j:" << j << endl;
            hash[i][dest_j] = true;
        }
        for (int j = 0; j < n; ++j) {
            int dest_i = 0;
            int dest_max = INT_MIN;
            for (int i = 0; i < m; ++i) {
                if (matrix[i][j] > dest_max) {
                    dest_max = matrix[i][j];
                    dest_i = i;
                }
            }
            if (hash[dest_i][j]) {
                res.push_back(matrix[dest_i][j]);
            }
        }
        return res;
    }
};
