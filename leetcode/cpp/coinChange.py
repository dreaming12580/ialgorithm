
def coinChange(coins: List[int], amount: int):

  def dp(n):
    #base case
    if n == 0: return 0
    if n < 0:  return -1
    
    #求最小值， 所以初始化为正无穷
    res = float('INF')
    for coin in coins:
      subproblem = dp(n - coin)
      #子问题无解，跳过
      if subproblem == -1: continue
      res = min(res, 1 + subproblem)

    return res if res != float('INF') else -1

  return dp(amount)







