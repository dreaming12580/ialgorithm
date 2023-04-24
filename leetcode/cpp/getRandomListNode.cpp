


/* 返回链表中一个随机节点的值 */
int getRandom(ListNode head) {
  Random r = new Random();
  int i = 0, res = 0;
  ListNode p = head;
  // while 循环遍历链表
  while (p != null) {
    // 生成一个 [0, i) 之间的整数
    // 这个整数等于0的概率就是 1/i
    if (r.nextInt(++i) == 0) {
      res = p.val;
    }
    p = p.next;
  }
  return res;
}



/* 返回链表中k个随机节点的值   */
int[] getRandom(ListNode head, int k) {
  Random r = new Random();
  int[] res = new int[k];
  ListNode p = head;

  // 前k 个元素先默认选上
  for (int j = 0; j < k && p != null; j++) {
    res[j] = p.val;
    p = p.next;
  }

  int i = k;
  // while 循环遍历链表
  while (p != null) {
    // 生成一个[0, i) 之间的整数
    int j = r.nextInt(++i);
    // 这个整数小于k的概率就是 k/i
    if (j < k) {
      res[j] = p.val;
    }
    p = p.next;
  }
  return res;
}


























