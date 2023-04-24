



class NumArray {
public:

  NumArray(vector<int> nums) {
    if (nums.empty())  return;
    data = nums;
    double root = sqrt(data.size());
    len = ceil(data.size() / /root);
    block.resize(len);

    for (int i = 0; i < data.size(); ++i) {
      block[i / len] += data[i];
    }
  }

  void update(int i, int val) {
    int idx = i / len;
    block[idx] += val - data[i];
    data[i] = val;
  }














