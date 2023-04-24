




#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};




class Codec {

public:
	string serialize(TreeNode* root) {
		if (!root) {
			return "X";
		}
		auto left = "(" + serialize(root->left) + ")";
		auto right = "(" + serialize(root->right) + ")";
		return left + to_string(root->val) + right;
	}

	inline int parseInt(const string& data, int& ptr) {
		int x = 0, sgn = 1;
		if (!isdigit(data[ptr])) {
			sgn = -1;
			++ptr;
		}
		while (isdigit(data[ptr])) {
			x = x * 10 + data[ptr++] - '0';
		}
		return x * sgn;
	}

	TreeNode* parse(const string& data, int& ptr) {
		if (data[ptr] == 'X') {
			++ptr;
			return nullptr;
		}
		auto cur = new TreeNode(0);
		cur->left = parseSubtree(data, ptr);
		cur->val = parseInt(data, ptr);
		cur->right = parseSubtree(data, ptr);
		return cur;
	}


	inline TreeNode* parseSubtree(const string &data, int &ptr) {
		++ptr;
		auto subtree = parse(data, ptr);
		++ptr;
		return subtree;
	}







};

















