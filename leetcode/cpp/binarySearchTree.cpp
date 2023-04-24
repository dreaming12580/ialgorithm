

boolean isValidBST(TreeNode root) {
  return isValidBST(root, null, null);
}

/* 限定以root为根的子树节点必须满足 min.val < root.val < max.val */
boolean isValidBST(TreeNode root, TreeNode min, TreeNode max) {
  // base case
  if (root == null) return true;
  // 若root.val 不符合max和min的限制， 说明不是合法的BST
  if (min != null && root.val <= min.val) return false;
  if (max != null && root.val >= max.val) return false;
  // 限定左子树的最大值为root.val,  右子树的最小值为root.val
  return isValidBST(root.left, min, root) &&
      isValidBST(root.right, root, max);
}


boolean isInBST(TreeNode root, int target) {
  if (root == null) {
    return false;
  } else if (root.val == target) {
    return true;
  } else if (root.val < target) {
    return isInBST(root.right, target);
  } else if (root.val > target) {
    return isInBST(root.left, target);
  }
}




TreeNode insertIntoBST(TreeNode root, int val) {
  // 找到空位置插入新节点
  if (root == null) return new TreeNode(val);
  // if (root.val == val) BST 中一般不会插入已存在元素
  if (root.val < val) {
    root.right = insertIntoBST(root.right, val);
  } else if (root.val > val) {
    root.left = insertIntoBST(root.left, val);
  }
  return root;
}


TreeNode deleteNode(TreeNodee root, int key) {
  if (root == null) return null;
  if (root.val == key) {
    // 这两个 if 把情况1和2都正确处理了
    if (root.left == null) return root.right;
    if (root.right == null) return root.left;
    // 处理情况3
    TreeNode minNode = getMin(root.right);
    root.val = minNode.val;
    root.right = deleteNode(root.right, minNode.val);
  } else if (root.val > key) {
    root.left = deleteNode(root.left, key);
  } else if (root.val < key) {
    root.right = deleteNode(root.right, key);
  }
  return root;
}

TreeNode getMin(TreeNode node) {
  // BST 最左边的就是最小的
  while (node.left != null) node = node.left;
  return node;
}











