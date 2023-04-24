class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());

        //检查二分的答案 d 是否合法
        auto check = [&] (int d) {
            // 记录一共取出几个数
            int cnt = 1;
            // j 指向上一次取得数， i 指向当前考虑的数
            for (int i = 1, j = 0; i < n; ++i) {
                // price[i] 是大于等于 price[j] + d 的最小值， 取出
                if (price[i] - price[j] >= d) {
                    ++cnt, j = i;
                }
            }
            return cnt >= k;
        };

        // 二分答案
        int left = 0, right = (price[n - 1] - price[0]) / (k - 1) + 1;
        while (left + 1 < right) {
            int mid = (left + right) >> 1;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
