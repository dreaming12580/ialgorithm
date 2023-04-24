


ListNode reverse(ListNode head) {
  if (head.next == null) return head;
  ListNode last = reverse(head.next);
  head.next.next = head;
  head.next = null;
  return last;
}

ListNode successor = null;  // 后驱节点

// 反转以head 为起点的n个节点， 返回新的头节点
ListNode reverseN(ListNode head, int n) {
  if (n == 1) {
    // 记录第 n + 1个节点
    successor = head.next;
    return head;
  }
  // 以head.next 为起点， 需要反转前n - 1个节点
  ListNode last = reverseN(head.next, n - 1);
  head.next.next = head;
  // 让反转之后的head节点和后面的节点连起来
  head.next = successor;
  return last;
}


ListNode reverseBetween(ListNode head, int m, int n) {
  // base case 
  if (m == 1) {
    return reverseN(head, n);
  }

  // 前进到反转的起点触发 base case 
  head.next = reverseBetween(head.next, m - 1, n - 1);
  return head;
}



















