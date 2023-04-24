




/* 主函数 */
int numTrees(int n) {
  // 计算闭区间[1, n]组成的BST个数
  return count(1, n);
}

/* 计算闭区间[lo, hi]组成的BST个数 */
int count(int lo, int hi) {
  // base case
  if (lo > hi) return 1;
  int res = 0;
  for (int i = lo; i <= hi; i++) {
    // i的值作为根节点root
    int left = count(lo, i - 1);
    int right = count(i + 1, hi);
    // 左右子树的组合数乘积是BST的总数
    res += left * right;
  }
  return res;
}










