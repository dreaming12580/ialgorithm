



#include <vector>
#include <string>

using namespace std;


class Solution {
private:
    static unordered_set<string> transit;

public:

    int longestBeautifulSubstring(string word) {
        int cur = 0, ans = 0;
        char status = 'x';

        for (char ch : word) {
            if (transit.count(string(1, status) + ch)) {
                if (status != 'a' && ch == 'a') {
                    cur = 1;
                } else {
                    ++cur;
                }
                status = ch;
            } else {
                status = 'x';
                cur = 0;
            }
            if (status == 'u') {
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};

unordered_set<string> Solution::transit = {
    "ae", "ei", "io", "ou",
    "aa", "ee", "ii", "oo", "uu",
    "xa", "ea", "ia", "oa", "ua"
};








