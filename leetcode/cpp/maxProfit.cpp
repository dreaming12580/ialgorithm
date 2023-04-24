



int max_k = 2;

int [][][] dp = new int[n][max_k + 1][2];

for (int i = 0; i < n; i++) {

  // 这里从大到小遍历， 是为了处理k的时候，用之前第i天的旧小k的逻辑
  for (int k = max_k; k >= 1; k--) {
    if (i - 1 == -1) { /*处理 base case */ }
    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);

  }
}

return dp[n-1][max_k][0];















