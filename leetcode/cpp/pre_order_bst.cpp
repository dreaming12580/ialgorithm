

vector<int> PreOrder(TreeNode* root) {
  vector<int> res;
  stack<TreeNode*> st;

  if (root == nullptr) {
    return res;
  }
  TreeNode* t = root;
  while (t || !st.empty()) {
    while (t) {
      st.push(t);
      res.push_back(t->val);
      t = t->left;
    }
    t = st.top();
    st.pop();
    t = t->right;
  } 
  return res;
}
















