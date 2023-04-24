#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int val;
};

class Solution {
private:
	bool recur(TreeNode* l, TreeNode* r) {
		if (l == nullptr && r == nullptr) {
			return true;
		}
		if (l == nullptr || r == nullptr || l->val != r->val) {
			return false;
		}
		return recur(l->left, r->right) && recur(l->right, r->left);
	}

public: 
	bool isSymmetric(TreeNode* root) {
		return root == nullptr ? true : recur(root->left, root->right);
	}

};











