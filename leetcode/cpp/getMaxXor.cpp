




#include <vector>
#include <algorithm>
#include <numeric>


using namespace std;

class Trie {
public:
    const int L = 30;
    Trie* children[2] = {};

    void insert(int val) {
        Trie* node = this;
        for (int i = L - 1; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new Trie();
            }
            node = node->children[bit];
        }
    }

    int getMaxXor(int val) {
        int ans = 0;
        Trie* node = this;
        for (int i = L - 1; i >= 0; --i) {
            int bit = (val >> i) & 1;
            if (node->children[bit ^ 1] != nullptr) {
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
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int qn = queries.size();

        vector<int> indices(qn);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return queries[i][1] < queries[j][1] ||
                (queries[i][1] == queries[j][1] && queries[i][0] < queries[j][0]);
        });

        int idx = 0;
        vector<int> ans(qn);
        Trie* t = new Trie();
        for (int i = 0; i < qn; ++i) {
            int l = queries[indices[i]][0];
            int r = queries[indices[i]][1];
            while (idx < n && nums[idx] <= r) {
                t->insert(nums[idx]);
                ++idx;
            }
            if (idx == 0) {
                ans[indices[i]] = -1;
            } else {
                ans[indices[i]] = t->getMaxXor(l);
            }
        }
        return ans;
    }






};






