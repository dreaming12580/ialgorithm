
#include <vector>
#include <unordered_map>



using namespace std;

struct TreeNode {

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val_) : val(val_), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    unordered_map<int, int> index;


public:
    TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder, 
            int preorder_left, int preorder_right,
            int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        int root_val = preorder[preorder_left];
        int inorder_index = index[root_val];
        TreeNode* root = new TreeNode(root_val);
        int size_left = inorder_index - inorder_left;
        root->left = myBuildTree(preorder, inorder, 
                preorder_left+1, preorder_left + size_left, 
                inorder_left, inorder_index - 1);
        root->right = myBuildTree(preorder, inorder,
                preorder_left + size_left + 1, preorder_right,
                inorder_index + 1, inorder_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 构造哈希映射， 帮助我们快速定位根节点
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }





};


































