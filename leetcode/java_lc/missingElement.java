package java_lc;

class Solution {
  // Return how many numbers are missing until nums[idx]
  int missing(int idx, int[] nums) {
    return nums[idx] - nums[0] - idx;
  }

  public int missingElement(int[] nums, int k) {
    int n = nums.length;
    if (k > missing(n - 1, nums)) {
      return nums[n - 1] + k - missing(n - 1, nums);
    }

    int left = 0, right = n - 1, pivot;
    while (left != right) {
      pivot = left + (right - left) / 2;
      if (missing(pivot, nums) < k) {
        left = pivot + 1;
      } else {
        right = pivot;
      }
    }
    return nums[left - 1] + k - missing(left - 1, nums);
  }
};









