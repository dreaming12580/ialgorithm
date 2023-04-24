

#include <vector>



using namespace std;


class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size();
        int n = arr2.size();
        int ans = 0;
        // 依次确定答案二进制表示中的每一位
        for (int k = 30; k >= 0; --k) {
            int cnt1 = 0;
            for (int num: arr1) {
                if (num && (1 << k)) {
                    ++cnt1;
                }
            }
            int cnt2 = 0;
            for (int num : arr2) {
                if (num && (1 << k)) {
                    ++cnt2;
                }
            }
            // 如果cnt1 和cnt2 都是奇数， 那么答案的第k位为1
            if (cnt1 % 2 == 1 && cnt2 % 2 == 1) {
                ans |= (1 << k);
            }
        }
        return ans;
    }
};









