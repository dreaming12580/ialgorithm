
#include <iostream>
#include <vector>
#include <stdint.h>
#include <limits.h>

using namespace std;


class Solution {

private:
    vector<int> f;
    vector<int> max_dis;

public:
    int minJump(vector<int>& jump) {
        int n = jump.size();

        // f[i] 表示到位置i，需要多少步数
        f.resize(n, INT_MAX);

        // max_dis[w] 表示w步可以跳到的最远位置
        max_dis.resize(n, 0);
        int ans = INT_MAX;

        f[0] = 0;
        max_dis[0] = 0;
        int w = 0;
        for (int i = 0; i < n; i++) {
            if (i > max_dis[w]) {
                ++w;
            }
            // 用往左跳到达位置i, 的最小操作数w + 1
            if (i != 0) {
                f[i] = min(f[i], w + 1);
            }
            int next = i + jump[i];

            if (next >= n) {
                ans = min(ans, f[i] + 1);
            } else if (f[next] > f[i] + 1) {
                f[next] = f[i] + 1;
                max_dis[f[next]] = max(max_dis[f[next]], next);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> jump = {2, 5, 1, 1, 1, 1};
    Solution s;
    cout << "ans:" << s.minJump(jump) << endl;
    return 0;
}



















