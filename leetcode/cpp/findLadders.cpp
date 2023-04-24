


#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool canTranslate(string& from_, string& to_) {
        if (from_.size() != to_.size()) {
            return false;
        }
        int count = 0;
        for (int i = 0; i < from_.size(); ++i) {
            if (from_[i] != to_[i]) {
                count++;
            }
        }
        return count == 1;
    }

    bool hasRoute(string& curWord, string& endWord, vector<string>& wordList,
                vector<bool>& visited, vector<string>& result) {
        if (curWord == endWord) {
            return true;
        }
        for (int i = 0; i < wordList.size(); ++i) {
            if (visited[i] || !canTranslate(curWord, wordList[i])) {
                continue;
            }
            visited[i] = true;
            result.push_back(wordList[i]);
            if (hasRoute(wordList[i], endWord, wordList, visited, result)) {
                return true;
            }
            result.pop_back();
            // 如果运行到这一步， 意味着无法从i这个点找到路径，所以visited[i]无需改为false;
            // visited[i] = false;
        }
        return false;
    }

    vector<string> findLadders(string beginWord, string endWord, 
        vector<string>& wordList) {
        vector<string> result = {beginWord};
        vector<bool> visited(wordList.size(), false);
        if (hasRoute(beginWord, endWord, wordList, visited, result)) {
            return result;
        }
        return vector<string>();
    }
};




















