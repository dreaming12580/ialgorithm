

#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
  TreeNode* left;
  TreeNode* right;
  int val;
};

void traverse(TreeNode* root, vector<vector<int>>& res) {
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    int level = q.size();
    vector<int> rev;
    while (level--) {
      TreeNode* node = q.front();
      q.pop();
      rev.push_back(node->val);
      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
    }
    res.push_back(rev);
  }
}

int main() {
  TreeNode* root;
  vector<vector<int>> res;
  traverse(root, res);
  for (auto& rev : res) {
    for (auto it : rev) {
      cout << it << " ";
    }
    cout << endl;
  }
  return 0;
}
















