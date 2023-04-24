

#include <vector>

using namespace std;




struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};


class MyBst {
public:
	MyBst(TreeNode* root) {
		this->root = root;
		countNodeNum(root);
	}

	// 返回二叉搜索树中第 k 小的元素
	int kthSmallest(int k) {
		TreeNode* node = root;
		while (node != nullptr) {
			int left = getNodeNum(node->left);
			if (left < k - 1) {
				node = node->right;
				k -= left + 1;
			} else if (left == k - 1) {
				break;
			} else {
				node = node->left;
			}
		}
		return node->val;
	}

private:
	TreeNode* root;
	unordered_map<TreeNode*, int> nodeNum;

	// 统计以 node 为根结点的子树的结点数
	int countNodeNum(TreeNode* node) {
		if (node == nullptr) {
			return 0;
		}
		nodeNum[node] = 1 + countNodeNum(node->left) + countNodeNum(node->right);
		return nodeNum[node];
	}

	// 获取以 node 为根结点的子树的结点数
	int getNodeNum(TreeNode* node) {
		if (node != nullptr && nodeNum.count(node)) {
			return nodeNum[node];
		} else {
			return 0;
		}
	}
};

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		MyBst bst(root);
		return bst.kthSmallest(k);
	}
};










