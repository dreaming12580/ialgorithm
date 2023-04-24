


class Solution {
    public int digitsCount(int d, int low, int high) {
        return count(high, d) - count(low - 1, d);
    }
    
    /* 计算数字 d 在 1-n 中出现的次数。 */
    public int count(int n, int d) {
        int cnt = 0, k;
        for (int i = 1;(k = n / i) != 0;i *= 10) {
            // 高位的数字。
            int high = k / 10;
            if (d == 0) {
                if (high != 0) {
                    high--;
                } else {
                    break;
                }
            }
            cnt += high * i;
            // 当前位的数字。
            int cur = k % 10;
            if (cur > d) {
                cnt += i;
            } else if (cur == d) {
                // n - k * i 为低位的数字。
                cnt += n - k * i + 1;
            }
        }
        return cnt;
    }
    
}










