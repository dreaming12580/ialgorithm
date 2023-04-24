






class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    // 先计算两个字符串的长度
    int m = text1.size();
    int n = text2.size();

    // 构建dp矩阵， 默认初始值0
    // 这里会多扩建一行和一列
    // 因为dp[i][j]的含义是: 对于s1[1..i] 和 s2[1..j], 他们的lcs长度是dp[i][j]
    // 所以当i 或者j 为零时， lcs的长度默认为0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // 状态转移
    // i, j都从1开始遍历，因为下面的操作中都会-1, 相当于从0开始
    for (int i = 1; i < m + 1; i++) {
      for (int j = 1; j < n + 1; j++) {
        // 如果text1 和text2 相同
        // 就在它们的前一位基础上加一
        dp[i][j] = (text1[i-1] == text2[j-1]) ? dp[i-1][j-1] + 1 : max(dp[i-1][j], dp[i][j-1]);
      }
    }
    
    // 返回最终右下角的值
    return dp[m][n];
  }
}












