

#include <vector>
#include <algorithm>
using namespace std;


class Solution {

public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        // 1. 首先从后向前查找第一个顺序对 (i,i+1)(i,i+1)，满足 a[i] < a[i+1]。
        // 这样「较小数」即为 a[i]。此时 [i+1,n) 必然是下降序列。
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            // 2. 如果找到了顺序对，那么在区间[i+1,n) 中
            // 从后向前查找第一个元素j 满足 a[i] < a[j]。
            // 这样「较大数」即为 a[j]。
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            // 交换a[i]与a[j]
            swap(nums[i], nums[j]);
        }
        // 可以证明区间[i+1, n)必为降序。
        // 直接使用双指针反转区间[i+1, n)使其变为升序，
        // 而无需对该区间进行排序
        reverse(nums.begin() + i + 1, nums.end());
    }
};











