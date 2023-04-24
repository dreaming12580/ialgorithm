#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
const int N = 50010;

int n;
int id[N];
pair<PII, int> cows[N];

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> cows[i].first.first >> cows[i].first.second;
    cows[i].second = i;
  }
  // 按照 pair<开始使用时间， 结束使用时间> 进行排序
  sort(cows, cows + n);

  // pair< 当前围栏的最后使用的时间, 当前分配的围栏id > 
  priority_queue<PII, vector<PII>, greater<PII>> heap;
  for (int i = 0; i < n; ++i) {
    if (heap.empty() || heap.top().first >= cows[i].first.first) {
      PII stall = {cows[i].first.second, heap.size()};
      id[cows[i].second] = stall.second;
      heap.push(stall);
    } else {
      // 更新当前围栏的最后使用时间
      auto stall = heap.top();
      heap.pop();
      stall.first = cows[i].first.second;
      id[cows[i].second] = stall.second;
      heap.push(stall);
    }
  }

  cout << heap.size() << endl;
  for (int i = 0; i < n; ++i) {
    cout << id[i] + 1 << endl;
  }
  return 0;
}










