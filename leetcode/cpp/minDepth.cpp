




int minDepth(TreeNode root) {
  if (root == nullptr) return 0;
  Queue<TreeNode> q = new LinkedList<>();
  q.offer(root);
  // root 本身就是一层， depth初始化为1
  int depth = 1;

  while (!q.isEmpty()) {
    int sz = q.size();
    /* 将当前队列中的索引节点向四周扩散 */
    for (int i = 0; i < sz; i++) {
      TreeNode cur = q.poll();
      /* 判断是否到达终点 */
      if (cur.left == null && cur.right == null) {
        return depth;
      }
      /* 将cur的相邻节点加入队列 */
      if (cur.left != null) {
        q.offer(cur.left);
      }
      if (cur.right != null) {
        q.offer(cur.right);
      }
    }
    /* 这里增加步数 */
    depth++;
  }
  return depth;
}
















