

// 左侧指针

ListNode left;

boolean isPalindrome(ListNode head) {
  left = head;
  return traverse(head);
}

boolean traverse(ListNode right) {
  if (right == null) return true;
  boolean res = traverse(right.next);
  // 后序遍历代码
  res = res && (right.val == left.val);

  left = left.next;
  return res;
}



///////////////////////////////////////

boolean isPalindrome(ListNode head) {
  ListNode slow, fast;
  slow = fast = head;
  while (fast != null && fast.next != null) {
    slow = slow.next;
    fast = fast.next.next;
  }

  // slow 指针现在指向链表中点
  // 如果fast 指针没有指向null, 说明链表长度为奇数，slow 还要再前进一步
  if (fast != null) {
    slow = slow.next;
  }

  // 从slow 开始反转后面的链表， 现在可以开始比较回文串
  ListNode left = head;
  ListNode right = reverse(slow);

  while (right != null) {
    if (left.val != right.val) {
      return false;
    }
    left = left.next;
    right = right.next;
  }
  return true;
}

ListNode reverse(ListNode head) {
  ListNode pre = null, cur = head;
  while (cur != null) {
    ListNode next = cur.next;
    cur.next = pre;
    pre = cur;
    cur = next;
  }
  return pre;
}

} 











