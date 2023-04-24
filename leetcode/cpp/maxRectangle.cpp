#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


struct Node{
    bool leaf;
    vector<Node *> next;
    Node(): leaf(false), next(26, nullptr) {}
};

class Solution {
    // Global Variable:
    Node root;
    vector<string> ans;
    unordered_map<int, unordered_set<string>> _data;
    int _word_max_len, _ans_max_area;
    
    
    // Construct Trie:
    void insertTrie(vector<string> &words){
        for(const auto &w: words){
            auto tmp = &root;
            for(const auto &c: w){
                if( !tmp->next[c - 'a'] ){
                    tmp->next[c - 'a'] = new Node();
                }
                tmp = tmp->next[c - 'a'];
            }
            tmp->leaf = true;
        }
    }
    
    // Partion strings by length;
    void partionStrings(vector<string> &words){
        for(const auto &w: words){
            if(_word_max_len < w.size())
                _word_max_len = w.size();
            _data[w.size()].insert(w);
        }
    }
    
    // Judge if curr matrix is valid;
    int isValid(vector<string>& curr_ans){
        int m = curr_ans.size();
        int n = curr_ans[0].size();
        bool isNotLeaf = false;
        for(int i = 0; i < n; ++i){
            auto tmp = &root;
            for(int j = 0; j < m; ++j){
                if( !tmp->next[curr_ans[j][i] - 'a'] )
                    return 0;
                tmp = tmp->next[curr_ans[j][i] - 'a'];
            }
            if(tmp->leaf == false)
                isNotLeaf = true;
        }
        return isNotLeaf ? 1 : 2;
    }
    
    void dfs( vector<string>& curr_ans, unordered_set<string>& S){
        if( S.begin()->size() * _word_max_len <= _ans_max_area )
            return ;
        if(curr_ans.size() >= _word_max_len)
            return ;
        for(const auto &w: S){
            curr_ans.push_back(w);
            auto flag = isValid(curr_ans);
            if(flag == 1){
                dfs(curr_ans, S);
            } else if(flag == 2){
                if( _ans_max_area < currAns.size() * currAns[0].size() ){
                    ans = curr_ans;
                    _ans_max_area = currAns.size() * currAns[0].size();
                }
                dfs(currAns, S);
            }
            curr_ans.pop_back();
        }
    }
    
public:
    // constructor
    Solution(): _root(), _ans(), _data(), _word_max_len(0), _ans_max_area(0) {}
    
    vector<string> maxRectangle(vector<string>& words) {
        insertTrie(words);
        partionStrings(words);
        for(auto &pir: _data){
            vector<string> curr_ans;
            dfs(curr_ans, pir.second);
        }
        return _ans;
    }
};







