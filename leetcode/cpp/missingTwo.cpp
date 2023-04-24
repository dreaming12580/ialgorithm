#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        bitset<30003> bt;
        for (auto &num : nums) {
            bt.set(num);
        }
        vector<int> res;
        for (int i = 1; i <= 30002; i++) {
            if (!bt[i]) {
                res.push_back(i);
                if (res.size() == 2) {
                    return res;
                }
            }
        }
        return res;
    }
};






