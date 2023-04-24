
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int getMinSwaps(string num, int k) {
        string num_k = num;
        for (int i = 0; i < k; ++i) {
            next_permutation(num_k.begin(), num_k.end());
        }
        int n = num.size();
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            if (num[i] != num_k[i]) {
                for (int j = i + 1; j < n; ++j) {
                    if (num[j] == num_k[i]) {
                        for (int k = j - 1; k >= i; --k) {
                            ++ans;
                            swap(num[k], num[k + 1]);
                        }
                        break;
                    }
                }
            }
        }
        return ans;
    }
};




