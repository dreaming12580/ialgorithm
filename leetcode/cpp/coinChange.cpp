
#include <vector>

using namespace std;


// dp数组的迭代解法

// dp[i] = x 表示， 当目标金额为i时， 至少需要x枚硬币

int coinChange(vector<int>& coins, int amount) {

  // 数组大小为amount + 1, 初始值为amount + 1
  vector<int> dp(amount + 1, amount + 1);
  
  //base case
  dp[0] = 0;
  for (int i = 0; i < dp.size(); i++) {
    // 内层for 在求所有子问题 + 1的 最小值
    for (int coin: coins) {
      //子问题无解， 跳过
      if (i - coin < 0) continue;
      dp[i] = min(dp[i], 1 + dp[i - coin]);
    }
  }
  return (dp[amount] == amount + 1) ? -1: dp[amount];
}


















