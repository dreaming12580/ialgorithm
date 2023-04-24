

from functools import cache


RULES = {
  'e': (0, 4, 7),
  'l': (3, 3, 3),
  'o': (5, 2, 3),
  'h': (7, 1, 1),
  't': (8, 1, 1),
  'c': (9, 1, 1),
  'd': (10, 1, 1),
}

FULL = 2012 # 0b11111011100，每个字母都选到了对应的上限

inf = 0x3f3f3f3f

# 合并两种选择字母的方案
def merge(cur: int, add: int) ->int:
  for pos, limit, m in RULES.values():
    c1 = (cur >> pos) & m
    c2 = (add >> pos) & m  
    if c1 + c2 > limit:
      return -1
    cur += c2 << pos
  return cur

class Solution:
  def Leetcode(self, words: List[str]) -> int:
    # 预处理每个单词的每种选择字母的方案所消耗的代币的最小值
    costs = []
    for word in words:
      cost = {}
      def dfs(s: str, mask: int, tot: int) -> None:
        if mask not in cost or tot < cost[mask]:
          cost[mask] = tot
        # 枚举选择字母的位置
        for i, c in enumerate(s):
          if c not in RULES:
            continue
          pos, limit, m = RULES[c]
          if (mask >> pos & m < limit):
            # 可以选择字母 c
            dfs(s[:i] + s[i + 1:], mask + (1 << pos), tot + i * (len(s) - 1 - i))
      dfs(word, 0, 0)
      costs.append(cost)

    @cache
    def dfs(i: int, mask: int) -> int:  
      if i == len(words):
        return 0 if mask == FULL else inf
      res = inf
      for add, tot in costs[i].items():
        if tot >= res:
          continue
        m = merge(mask, add)
        if m >= 0:
          res = min(res, tot + dfs(i + 1, m))
      return res
    ans = dfs(0, 0)
    return ans if ans < inf else -1