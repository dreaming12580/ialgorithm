


class Solution {

public:
    int maximum(int a, int b) {
        int a_sign = (a >> 31) & 1, b_sign = (b >> 31) & 1;
        int diff = a_sign ^ b_sign;
        int k = (diff & b_sign) | ((diff ^ 1) & ((b - a) >> 31) & 1);
        return k * a + (k ^ 1) * b;
    }








};












