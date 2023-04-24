



class Solution {
public:
    int countSubstrings(string s, string t) {
        int m = s.length(), n = t.length();
        // dp[i][j] 以s[i][j]为终点，且左侧字符连续相等的数量
        vector<vector<int>> dpl(m + 1, vector<int>(n + 1, 0));
        // dpr[i][j] 以s[i - 1][j - 1]为终点，且右侧字符连续相等的数量
        vector<vector<int>> dpr(m + 1, vector<int>(n + 1, 0));
        

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i] == t[j]) {
                    dpl[i + 1][j + 1] = dpl[i][j] + 1;
                }
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (s[i] == t[j]) {
                    dpr[i][j] = dpr[i + 1][j + 1] + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i] != t[j]) {
                    ans += (dpl[i][j] + 1) * (dpr[i + 1][j + 1] + 1);
                }
            }
        }
        return ans;
    }
};






