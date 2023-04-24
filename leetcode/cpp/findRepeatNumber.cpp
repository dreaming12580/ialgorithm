#include <vector>
#include <algorithm>

using namespace std;

// 原地置换法
class Solution {
public:
  int findRepeatNumber(vector<int>& nums) {
    int N = nums.size();
    for (int i = 0; i < N; i++) {
      while (nums[i] != i) {
        int temp = nums[i];
        if (nums[temp] == temp) {
          return temp;
        } else {
          swap(nums[temp], nums[i]);
        }
      }
    }
    return -1;
  }
};







