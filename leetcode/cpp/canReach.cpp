#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> f(n), pre(n);
        f[0] = 1;
        pre[0] = 1;
        int i = 1;
        for (; i < minJump; ++i) {
            pre[i] = pre[i - 1];
        }
        for (; i < n; ++i) {
            int l = i - maxJump;
            int r = i - minJump;
            if (s[i] == '0') {
                int total = pre[r] - (l <= 0 ? 0 :pre[l - 1]);
                f[i] = (total != 0);
            } 
            pre[i] = f[i] + pre[i - 1];
        }
        return f[n - 1] == 1;
    }
};