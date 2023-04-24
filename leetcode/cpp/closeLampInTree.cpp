/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Node {
public:
	TreeNode* curr;
	bool switch2;
	bool switch3;

	Node(TreeNode* _curr, bool _switch2, bool _switch3) : curr(_curr), switch2(_switch2), switch3(_switch3) {}

	bool operator==(const Node& p) const {
		return curr == p.curr && switch2 == p.switch2 && switch3 == p.switch3;
	}
};

struct hash_fn {
	std::size_t operator() (const Node& node) const {
		std::size_t h1 = std::hash<TreeNode*>()(node.curr);
		std::size_t h2 = std::hash<bool>()(node.switch2);
		std::size_t h3 = std::hash<bool>()(node.switch3);
		return h1 ^ h2 ^ h3;
	}
};


class Solution {

public:
	int closeLampInTree(TreeNode* root) {
		unordered_map<Node, int, hash_fn> memo;
		function<int(TreeNode*,bool,bool)> dfs = [&](TreeNode* node, bool switch2, bool switch3) ->int {
			if (!node) {
				return 0;
			}
			Node curr(node, switch2, switch3);
			if (memo.count(curr)) {
				return memo[curr];
			}
			if ((node->val == 1) == (switch2 == switch3)) {
				int res1 = dfs(node->left, switch2, false) + dfs(node->right, switch2, false) + 1;
				int res2 = dfs(node->left, !switch2, false) + dfs(node->right, !switch2, false) + 1;
				int res3 = dfs(node->left, switch2, true) + dfs(node->right, switch2, true) + 1;
				int res123 = dfs(node->left, !switch2, true) + dfs(node->right, !switch2, true) + 3;
				memo[curr] = min({res1, res2, res3, res123});
			} else {
				int res0 = dfs(node->left, switch2, false) + dfs(node->right, switch2, false);
				int res12 = dfs(node->left, !switch2, false) + dfs(node->right, !switch2, false) + 2;
				int res13 = dfs(node->left, switch2, true) + dfs(node->right, switch2, true) + 2;
				int res23 = dfs(node->left, !switch2, true) + dfs(node->right, !switch2, true) + 2;
				memo[curr] = min({res0, res12, res13, res23});
			}
			return memo[curr];
		};
		return dfs(root, false, false);
	}
};














