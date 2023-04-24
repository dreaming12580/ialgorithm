
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;


class Solution {
private:
    bool isCombinated(string word, unordered_set<string>& us) {
        if (word.size() == 0) {
            return true;
        }
        for (int i = word.size(); i > 0; --i) {
            if (us.count(word.substr(0, i)) &&
                isCombinated(word.substr(i), us)) {
                    return true;
            }
        }
        return false;
    }

public:
    string longestWord(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](string& f, string& s) {
            return f.length() > s.length() || 
                    (f.length() == s.length() && f < s);
        });
        unordered_set<string> us(words.begin(), words.end());
        for (auto word : words) {
            us.erase(word);
            if (isCombinated(word, us)) {
                return word;
            }
        }
        return string();
    }
};














