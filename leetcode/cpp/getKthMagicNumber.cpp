#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> vec = {1};
        int curr_3 = 3, curr_5 = 5, curr_7 = 7;
        int idx_3 = 0, idx_5 = 0, idx_7 = 0;
        int curr = vec.back();
        while (--k) {
            if (curr_3 < curr_5 && curr_3 < curr_7) {
                vec.push_back(curr_3);
                curr = curr_3;
                do {
                    idx_3++;
                    curr_3 = 3 * vec[idx_3];
                } while (curr_3 == curr_5 || curr_3 == curr_7);
            } else if (curr_5 < curr_3 && curr_5 < curr_7) {
                vec.push_back(curr_5);
                curr = curr_5;
                do {
                    idx_5++;
                    curr_5 = 5 *vec[idx_5];
                } while (curr_5 == curr_3 || curr_5 == curr_7);
            } else {
                vec.push_back(curr_7);
                curr = curr_7;
                do {
                    idx_7++;
                    curr_7 = 7 * vec[idx_7];
                } while (curr_7 == curr_3 || curr_7 == curr_5);
            }
            cout << "curr:" << curr << " " << curr_3 << " " << curr_5 << " " << curr_7 << endl;
        }
        
        return curr;
    }
};






