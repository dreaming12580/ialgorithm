
#include <sstream>
#include <deque>
#include <string>

using namespace std;


class Solution {

public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if (sentence1.size() < sentence2.size()) {
            swap(sentence1, sentence2);
        }
        // first
        if (sentence2 == sentence1) {
            return true;
        }
        deque<string> q1, q2;
        string w;
        istringstream cinA(sentence1);
        istringstream cinB(sentence2);
        while (cinA >> w) {
            q1.emplace_back(w);
        }
        while (cinB >> w) {
            q2.emplace_back(w);
        }
        // 3 possibilities
        while (1) {
            if (!q2.empty() && q1.back() == q2.back()) {
                q1.pop_back();
                q2.pop_back();
            } else if (!q2.empty() && q1.front() == q2.front()) {
                q1.pop_front();
                q2.pop_front();
            } else {
                break;
            }
        }
        return q2.empty();
    }
};











