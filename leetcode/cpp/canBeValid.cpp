#include <string>

using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        int nx = 0, nm = 0;

        for (int i = 0; i < n; ++i) {
            int diff = 0;
            if (s[i] == '(') {
                diff = 1;
            } else {
                diff = -1;
            }
            if (locked[i] == '1') {
                nx += diff;
                nm = max(nm + diff, ((i + 1) % 2));
            } else {
                nx += 1;
                nm = max(nm - 1, ((i + 1) % 2));
            }
            if (nx < nm) {
                return false;
            }
        }
        return nm == 0;
    }
};













