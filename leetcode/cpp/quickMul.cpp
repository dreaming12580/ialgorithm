
class Solution {
public:
	double quickMul(double x, int n) {
		double res = 1.0;
		int i = n;
		while (i) {
			// i 的最低位是否为 1
			if (i & 1) {
				res *= x;
			}
			// i 右移一位， 注意不能用 i >>= 1, 因为负数的移位运算不同于整数，
			// -1 >> 1 永远为 -1 !
			i /= 2;
			// x ^ 1, x ^ 2, x ^ 4, x ^ 8 ...
			x *= x;
		}
		return n < 0 ? 1 / res : res;
	}
};












