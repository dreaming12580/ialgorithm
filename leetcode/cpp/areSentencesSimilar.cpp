


#include <vector>
#include <string>


using namespace std;

class Solution {
private:
    //// split函数
    vector<string> split(string s) {
        int n = s.size();
        vector<string> res;
        int L = 0, R = 0;
        while (R < n) {
            if (s[R] != ' ') {
                R++;
            } else {
                string cur = s.substr(L, R - L);
                res.push_back(cur);
                R++;
                L = R;
            }
        }
        if (L != R) {
            string cur = s.substr(L, R - L);
            res.push_back(cur);
        }
        return res;
    }




public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        /// 两边剔的思想
        string s1 = sentence1, s2 = sentence2;
        if (s1 == s2) return true;
        if (s1.size() > s2.size()) {
            swap(s1, s2);
        }
        vector<string> a1 = split(s1);
        vector<string> a2 = split(s2);
        while (!a1.empty()) {
            if (!(a1[0] == a2[0] || a1.back() == a2.back())) {
                return false;
            }
            if (a1[0] == a2[0]) {
                a1.erase(a1.begin());
                a2.erase(a2.begin());
            }
            if (a1.size() > 0 && a1.back() == a2.back()) {
                a1.pop_back();
                a2.pop_back();
            }
        }
        return true;
    }



};













