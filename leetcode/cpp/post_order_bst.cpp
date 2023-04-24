



vector<int> PostOrder(TreeNode* root) {
  vector<int> res;
  stack<int> st;
  TreeNode* cur = root;
  TreeNode* pre = nullptr;

  if (root == nullptr) {
    return res;
  }

  while (cur) {
    // 走到最左边孩子
    st.push(cur);
    cur = cur->left;
  }

  while (!st.empty()) {
    cur = st.top();
    if (cur->right == nullptr || cur->right == pre) {
      res.push_back(cur->val);
      pre = cur;
      st.pop();
    } else {
      cur = cur->right;
      while (cur) {
        st.push(cur);
        cur = cur->left;
      }
    }
  }
  return res;
}













