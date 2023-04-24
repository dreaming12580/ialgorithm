#include <vector>
#include <iostream>
#include <stack>

using namespace std;

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
        cout << "(" << i << " - " << left << " - 1) *" << currHeight << endl;
      }
      stk.push(i);
    }
    return ans;
  }
};

int main() {

  vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};
  Solution s;
  cout << "trap:" << s.trap(h) << endl;
  return 0;
}



