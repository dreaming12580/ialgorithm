#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* convertBiNode(TreeNode* root) {
        TreeNode dummy;
        TreeNode* prev = &dummy;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            prev->left = nullptr;
            prev->right = curr;
            prev = curr;
            curr = curr->right;
        }
        prev->left = nullptr;
        prev->right = nullptr;
        return dummy.right;
    }
};






