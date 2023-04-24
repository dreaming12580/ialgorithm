

#include <vector>


using namespace std;

struct Trie {
    // 左子树指向表示0的子节点
    Trie* left = nullptr;
    // 右子树指向表示1的子节点
    Trie* right = nullptr;

    Trie() {}
};


class Solution {
private:
    // 字典树的根节点
    Trie* root = new Trie();
    // 最高位的二进制编号为30
    static constexpr int HIGH_BIT = 30;

public:
    void add(int num) {
        Trie* cur = root;
        for (int k = HIGH_BIT; k >= 0; --k) {
            int bit = (num >> k) & 1;
            if (bit == 0) {
                if (!cur->left) {
                    cur->left = new Trie();
                }
                cur = cur->left;
            } else {
                if (!cur->right) {
                    cur->right = new Trie();
                }
                cur = cur->right;
            }
        }
    }

    int check(int num) {
        Trie* cur = root;
        int x = 0;
        for (int k = HIGH_BIT; k >= 0; --k) {
            int bit = (num >> k) & 1;
            if (bit == 0) {
                // a_i的第k个二进制位为0， 应当往表示1的子节点right走
                if (cur->right) {
                    cur = cur->right;
                    x = x * 2 + 1;
                } else {
                    cur = cur->left;
                    x = x * 2;
                }
            } else {
                // a_i的第k个二进制位为1， 应当往表示0的子节点left走
                if (cur->left) {
                    cur = cur->left;
                    x = x * 2 + 1;
                } else {
                    cur = cur->right;
                    x = x * 2;
                }
            }
        }
        return x;
    }




    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (int i = 1; i < n; ++i) {
            // 将 nums[i - 1]放入字典树， 此时 nums[0 .. i -1]都在字典树中
            add(nums[i - 1]);
            // 将 nums[i] 看作ai, 找出最大的 x 更新答案
            x = max(x, check(nums[i]));
        }
        return x;
    }
};











