


####################################################

def dp[K, N]:
  if K == 1: return N
  if N == 0: return 0



  for 1 <= i <= N:
  #最坏情况下的最少扔鸡蛋次数
    res = min(res, max(dp(k - 1, i - 1), dp(k, N - i)) + 1);

  return res;






def superEggDrop(K: int,  N: int):
  memo = dict()
  def dp[K, N] -> int:
    # base case
    if K == 1: return N
    if N == 0: reutnr 0
    # 避免重复计算
    if (K, N) in memo:
      return memo[(K, N)]

    res = float('INF')
    #穷举所有可能的选择
    for i in range(1, N + 1):
      res = min(res, max(dp(K, N - i), dp(k - 1, i - 1)) + 1);
    memo[(K, N)] = res
    return res

  return dp(K, N)




########################################













#当前有k个鸡蛋， 可以尝试扔m次鸡蛋，
# 这个状态下， 最坏情况下最多能确切测试一栋n层的楼
dp[k][m] = n

int superEggDrop(int K, int N) {
  // m 最多不会超过N次（线性扫描）
  int[][] dp = new int[K + 1][N + 1];


  //base case
  // dp[0][...] = 0;
  // dp[..][0] = 0;

  int m = 0;
  while (dp[K][m] < N) {
    m++;
    for (int k = 1; k <= K; k++) {
      dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1;
    }
  }
  return m;
}




##########################

for (int m = 1; dp[K][m] < N; m++) {
  for (int k = 1; k <= K; k++) {
    dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1;
  }
}




















































