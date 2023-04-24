#include <iostream>

using namespace std;


class Solution {


public:
    int add(int a, int b) {
        while (b != 0) {
            auto carry = (unsigned int)(a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};

int main() {
    Solution s;
    cout << "add(-3, -4):" << s.add(-3, -4) << endl;
    

}







