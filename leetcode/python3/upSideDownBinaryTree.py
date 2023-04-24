

class Solution:
  def upsideDownBinaryTree(self, root: TreeNode) -> TreeNode:
    parent = parent_right = None
    while root:
      root_left = root.left
      root.left = parent_right
      parent_right = root.right
      root.right = parent
      parent = root
      root = root_left
    return parent

