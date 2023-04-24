





class Solution {
public:
  int trap(vector<int> height) {
    int n = height.size();
    int sum = 0;
    stack<int> st;
    for (int i = 0; i < n; ++i) {
      // 如果栈不空并且当前指向的高度大于栈顶高度就一直循环
      while (!st.empty() && height[i] > height[st.top()]) {
        int h = height[st.top()];
        st.pop();
        // 栈空就出去
        if (st.empty()) {
          break;
        }
        // 两堵墙之间的距离
        int dis = i - st.top() - 1;
        int minv = min(height[st.top()], height[i]);
        sum += dis * (minv - h);
      }
      st.push(i);
    }
    return sum;
  }
};










