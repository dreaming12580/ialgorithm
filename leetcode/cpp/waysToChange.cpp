
#include <vector>
#include <iostream>



using namespace std;


class Solution {

private:
    static constexpr int mod = 10000000007;
    static constexpr int coins[4] = {25, 10, 5, 1};

public:
    int waysToChange(int n) {
        vector<int> f(n + 1);
        f[0] = 1;
        for (int c = 0; c < 4; ++c) {
            int coin = coins[c];
            for (int i = coin; i <= n; ++i) {
                f[i] = (f[i] + f[i - coin]) % mod;
            }
        }
        return f[n];
    }
};



























