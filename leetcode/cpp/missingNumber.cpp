

int missingNumber(int[] nums) {
  int n = nums.length;
  int res = 0;
  // 先和新补的索引异或一下
  res ^= n;
  // 和其他的元素、索引做异或
  for (int i = 0; i < n; i++) {
    res ^= i ^ nums[i];
  }
  return res;
}



int missingNumber(int[] nums) {
  int n = nums.length;
  int res = 0;
  // 新补的索引
  res += n - 0;
  // 剩下的索引和元素的差加起来
  for (int i = 0; i < n; i++) {
    res += i - nums[i];
  }
  return res;
}












