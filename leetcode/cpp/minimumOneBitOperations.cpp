





// f(pow(2, n)) = pow(2, n+1) - 1;


class Solution {
private:
    // 将当前数变为0， 需要的操作数
    int f(int n) {
        if (n <= 1) {
            return n;
        }
        int t = 32 - _builtin_clz(n) - 1;
        return (1 << t) + g(n ^ (1 << t), t - 1);
    }

    // 把当前数变为10...0, 如果1对应的位置已经是1， 我们只需要将后面的数变为0
    // 否则, 我们需要先把后面变为10...0, 将最高位翻转， 再将剩下的数变为0
    int g(int n, int t) {
        if (t == 0) {
            // 这时， n只可能是0或者1
            return 1 - n;
        }
        if (n & (1 << t)) {
            return f(n ^ (1 << t));
        }
        return 1 + (1 << t) - 1 + g(n, t - 1);
    }




public:
    int minimumOneBitOperations(int n) {
        return f(n);
    }


};