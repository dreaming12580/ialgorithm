class Solution {
public:

  int trap(vector<int>& height) {
    int sum = accumulate(height.begin(), height.end(), 0);
    int volume = 0;    // volume 
    int high = 1; 
    int size = height.size();
    int left = 0;    
    int right = size - 1;
    while (left <= right) {
      while (left <= right && height[left] < high) {
        left++;
      }
      while (left <= right && height[right] < high) {
        right--;
      }
      volume += right - left + 1; 
      high++;
    }
    return volume - sum;
  }
};
///////////////////////

class Solution {
public:

  int trap(vector<int>& height) {
    int ans = 0;
    stack<int> stk;
    int n = height.size();
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && height[i] > height[stk.top()]) {
        int top = stk.top();
        stk.pop();
        if (stk.empty()) {
          break;
        }
        int left = stk.top();
        int currWidth = i - left - 1;
        int currHeight = min(height[left], height[i]) - height[top];
        ans += currWidth * currHeight;
      }
      stk.push(i);
    }
    return ans;
  }
};










/////////////////////

class Solution {

public:
  int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) {
      return 0;
    }
    vector<int> leftMax(n);
    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i) {
      leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    vector<int> rightMax(n);
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += min(leftMax[i], rightMax[i]) - height[i];
    }
    return ans;
  }
};





