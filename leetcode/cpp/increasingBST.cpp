 
#include <stack>
#include <iostream>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* t = root;
        TreeNode* prev = nullptr;
        TreeNode* head = nullptr;
        while(t || !st.empty()) {
            while (t) {
                st.push(t);
                t = t->left;
            }

            t = st.top();
            st.pop();
            if (!head) {
                head = t;
            }
            if (prev) {
                prev->left = nullptr;
                prev->right = t;
            }
            cout << "val:" << t->val << endl;
            prev = t;
            t = t->right;
        }
        return head;
    }
};


int main() {

    TreeNode* t = new TreeNode(1);
    TreeNode* t1 = new TreeNode(3);
    TreeNode* t2 = new TreeNode(4, t1, nullptr);
    TreeNode* t3 = new TreeNode(2, t, t2);
    Solution s;
    s.increasingBST(t3);


    return 0;
}