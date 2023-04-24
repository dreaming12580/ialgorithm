/*
res[0]记录以root为根的二叉树是否是 BST，若为 1 则说明是 BST，若为 0 则说明不是 BST；
res[1]记录以root为根的二叉树所有节点中的最小值；
res[2]记录以root为根的二叉树所有节点中的最大值；
res[3]记录以root为根的二叉树所有节点值之和
*/

// 全局变量, 记录BST最大节点之和
int maxSum = 0;

/* 主函数 */
public int maxSumBST(TreeNode root) {
  traverse(root);
  return maxSum;
}

int[] traverse(TreeNode root) {
  // base case
  if (root == null) {
    return new int[] {
      1, Integer.MAX_VALUE, Integer.MIN_VALUE, 0};
  }

  // 递归计算左右子树
  int[] left = traverse(root.left);
  int[] right = traverse(root.right);

  /******  后序遍历位置 *******/
  int[] res = new int[4];
  // 这个if 在判断以root为根的二叉树是不是BST
  if (left[0] == 1 && right[0] == 1 &&
          root.val > left[2] && root.val < right[1]) {
    // 以 root 为根的二叉树是BST
    res[0] = 1;
    // 计算以root为根的这颗BST的最小值
    res[1] = Math.min(left[1], root.val);
    // 计算以root为根的这颗BST的最大值
    res[2] = Math.max(right[2], root.val);
    // 计算以root为根的这颗BST所有节点之和
    res[3] = left[3] + right[3] + root.val;
    //  更新全局变量
    maxSum = Math.max(maxSum, res[3]);
  } else {
    // 以root为根的二叉树不是BST
    res[0] = 0;
    // 其他的值没必要计算了， 因为这里用不到
  }
  return res;
}













