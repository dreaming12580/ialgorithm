

#include <vector>
#include <iostream>
#include <stack>

using namespace std;


class Solution {
private:
    using LL = long long;
    static constexpr int mod = 1000000007;

public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        // 数组left初始化为0， 数组right初始化为n - 1
        // 设置为元素不存在时的特殊值
        vector<int> left(n), right(n, n - 1);
        // 单调栈 (递增)
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                // 这里的right 是非严格定义的，
                // right[i]是右侧最近的小于等于nums[i]的元素下标
                right[st.top()] = i - 1;
                st.pop();
            }
            if (!st.empty()) {
                // 这里的left 是严格定义的， 
                // left[i]是左侧最近的严格小于nums[i]
                left[i] = st.top() + 1;
            }
            st.push(i);
        }

        // 前缀和
        vector<LL> pre(n + 1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }

        LL best = 0;
        for (int i = 0; i < n; ++i) {
            best = max(best, (pre[right[i] + 1] - pre[left[i]]) * nums[i]);
        }
        return best;
    }
};










