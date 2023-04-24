
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TrieNode {
    int idx;
    vector<TrieNode*> children;
    TrieNode() : idx(-1) {}
};





class Solution {
private:
    TrieNode* root;


public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        root = new TrieNode();
        int sn = smalls.size();
        for (int i = 0; i < sn; ++i) {
            string value = smalls[i];
            int len = value.size();
            TrieNode* node = root;
            for (int j = 0; j < len; ++j) {
                char t = value[j];
                if (node->children.size() <= t - 'a') {
                    node->children.resize(t - 'a' + 1, nullptr);
                }
                if (node->children[t - 'a'] == nullptr) {
                    node->children[t - 'a'] = new TrieNode();
                }
                node = node->children[t - 'a'];
            }
            node->idx = i;
        }

        int bn = big.size();
        vector<vector<int>> positions(sn, vector<int>());
        TrieNode* node = root;
        queue<TrieNode*> q;
        for (int i = 0; i < bn; ++i) {
            TrieNode* node;
            char t = big[i];
            int n = q.size();
            while (n--) {
                node = q.front();
                q.pop();
                if (node->children.size() <= t - 'a') {
                    continue;
                }
                if (!node->children[t - 'a']) {
                    continue;
                }
                node = node->children[t - 'a'];
                if (node->idx != -1) {
                    int len = smalls[node->idx].size();
                    positions[node->idx].push_back(i + 1 - len);
                }
                q.push(node);
            }
            node = root;
            if (node->children.size() <= t - 'a') {
                continue;
            }
            if (!node->children[t - 'a']) {
                continue;
            }
            node = node->children[t - 'a'];
            if (node->idx != -1) {
                positions[node->idx].push_back(i);
            }
            q.push(node);
        }
        return positions;
    }
};


















