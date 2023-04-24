
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <climits>
using namespace std;

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int val;
};

class Solution {
public:
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		vector<tuple<int, int, int>> nodes; 

		function<void(TreeNode*, int, int)> dfs = [&](TreeNode* node, int row, int col) {
			if (!node) {
				return;
			}
			nodes.emplace_back(col, row, node->val);
			dfs(node->left, row + 1, col - 1);
			dfs(node->right, row + 1, col + 1);
		};

		dfs(root, 0, 0);
		sort(nodes.begin(), nodes.end());
		vector<vector<int>> ans;
		int lastcol = INT_MIN;
		for (const auto& [col, row, value] : nodes) {
			if (col != lastcol) {
				lastcol = col;
				ans.emplace_back();
			}
			ans.back().push_back(value);
		}
		return ans;
	}
};





















