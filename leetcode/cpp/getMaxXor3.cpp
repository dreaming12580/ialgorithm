
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdint>
#include <climits>

using namespace std;

class Trie {
public:
    const int L = 30;
    Trie* children[2] = {};
    int min = INT_MAX;

    void insert(int val) {
        Trie* node = this;
        node->min = std::min(node->min, val);
        for (int i = L - 1; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new Trie();
            }
            node = node->children[bit];
            node->min = std::min(node->min, val);
        }
    }
    
    int getMaxXorWithLimit(int val, int limit) {
        Trie* node = this;
        if (node->min > limit) {
            return -1;
        }
        int ans = 0;
        for (int i = L - 1; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (node->children[bit ^ 1] != nullptr &&
                node->children[bit ^ 1]->min <= limit) {
                ans |= 1 << i;
                bit ^= 1;
            }
            node = node->children[bit];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie* t = new Trie();
        for (int val : nums) {
            t->insert(val);
        }
        int qn = queries.size();
        vector<int> ans(qn);
        for (int i = 0; i < qn; ++i) {
            ans[i] = t->getMaxXorWithLimit(queries[i][0], queries[i][1]);
        }
        return ans;
    }
};











