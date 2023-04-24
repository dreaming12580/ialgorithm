


int longestPalindromeSubSeq(string s) {
  int n = s.size();
  // dp 数组全部初始化为 1
  vector<int> dp(n, 1);

  for (int i = n - 2; i >= 0; i--) {
    // 存储 dp[i + 1][j - 1]的变量
    int pre = 0;
    for (int j = i + 1; j < n; j++) {
      int temp = dp[j];
      // 在这里， 一维dp数组中的数是什么
      if (s[i] == s[j]) {
        // dp[i][j] = dp[i + 1][j - 1] + 2;
        dp[j] = pre + 2;
      } else {
        // dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
        dp[j] = max(dp[j], dp[j - 1]);
      }
      pre = temp;
    }
  }
  return dp[n - 1];
}







//////////////////////////////////////////

int longestPalindromeSubseq(string s) {
  int n = s.size();
  // dp数组全部初始化为0
  vector<vector<int>> dp(n, vector<int>(n, 0));

  // base case 
  for (int i = 0; i < n; i++) {
    dp[i][i] = 1;
  }

  // 反着遍历保证正确的状态转移
  for (int i = n -1; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      // 状态转移方程
      if (s[i] == s[j]) {
        dp[i][j] = dp[i + 1][j - 1] + 2;
      } else {
        dp[i][j] = max(dp[i+1][j], dp[i][j -1]);
      }
    }
  }
  // 整个s的最长回文子串长度
  return dp[0][n - 1];
}






















