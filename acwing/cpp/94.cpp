
#include <bits/stdc++.h>


using namespace std;

int n, m;
vector<int> num;

void dfs(int k) {
  if (num.size() > m || num.size() + (n - k + 1) < m) {
    return;
  }
  // 到达枚举边界， 输出结果并结束
  if (k == n + 1) {
    for (int i = 0; i < num.size(); ++i) {
      cout << num[i] << " ";
    }
    cout << endl;
    return;
  }

  num.push_back(k);
  dfs(k + 1);
  num.pop_back();

  dfs(k + 1);
}

int main(void) {
  cin >> n >> m;
  dfs(1);

  return 0;
}











