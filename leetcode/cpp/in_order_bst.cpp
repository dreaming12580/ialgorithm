



vector<int> InOrder(TreeNode* root) {
  vector<int> res;
  stack<TreeNode*> st;
  
  if (root == nullptr) {
    return res;
  }
  TreeNode* t = root;
  while (t || !st.empty()) {
    while (t) {
      st.push(t);
      t = t->left;
    } 
    t = st.top();
    st.pop();
    res.push_back(t->val);
    t = t->right;
  }
}













