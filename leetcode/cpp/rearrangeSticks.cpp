

#include <vector>


using namespace std;


class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int rearrangeSticks(int n, int k) {
        vector<vector<int>> f(n + 1, vector<int>(k + 1));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            f[i][0] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[i][j] = f[i - 1][j - 1] + (i - 1) * f[i - 1][j];
            }
        }
        return f[n][k];
    }

};













