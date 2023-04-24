
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {

public:
    pair<int, double> DFS(TreeNode* root) {
        if (!root) return {0, 0.0};
        auto l = DFS(root->left);
        auto r = DFS(root->right);
        int a = l.first;
        double b = l.second;
        int c = r.first;
        double d = r.second;
        int tot = a + c + root->val;
        if ((a <= c && (c - 2 * d) <= a) || 
            (c <= a && (a - 2 * d) <= c)) {
                return {tot, (a + c) / 2.0};
        }
        if (a - 2 * b > c) {
            return {tot, b + c};
        } else {
            // c - 2 * d > a
            return {tot, a + d};
        }
    }

    double minimalExecTime(TreeNode* root) {
        auto p = DFS(root);
        return p.first - p.second;
    }
};







