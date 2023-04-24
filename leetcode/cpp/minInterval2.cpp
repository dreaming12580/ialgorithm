#include <bits/stdc++.h>
using namespace std;

struct Event {
  // 事件的类型， 0 表示左端点， 1 表示询问， 2 表示右端点
  int type;
  // 事件的位置
  int pos;
  // 事件的额外参数
  // 如果是 0 左端点事件， 那么 para 记录右端点的位置
  // 如果是 1 询问事件， 那么 para 记录它是第几个询问， 以便于返回答案数组
  // 如果是 2 右端点事件， 那么 para 记录左端点的位置
  int para;

  Event(int _type, int _pos, int _para) : type(_type), pos(_pos), para(_para) {}

  // 自定义比较函数， 按照事件的位置升序排序
  // 如果位置相同， 按照左端点、询问、右端点的顺序排序
  bool operator< (const Event& that) const {
    return pos < that.pos || (pos == that.pos && type < that.type);
  }
};

class Solution {
public:
  vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
    int n = intervals.size();
    int m = queries.size();

    vector<Event> events;
    for (int i = 0; i < m; ++i) {
      // 询问事件
      events.emplace_back(1, queries[i], i);
    }
    for (const auto& interval: intervals) {
      // 左端点事件
      events.emplace_back(0, interval[0], interval[1]);
      // 右端点事件
      events.emplace_back(2, interval[1], interval[0]);
    }
    sort(events.begin(), events.end());

    vector<int> ans(m, -1);
    // 存储区间长度的有序集合，支持重复元素
    multiset<int> seg;
    for (const auto& event: events) {
      if (event.type == 0) {
        // 左端点事件， 将区间长度加入有序集合
        seg.insert(event.para - event.pos + 1);
      } else if (event.type == 1) {
        // 询问事件，答案为有序集合中的最小值
        if (!seg.empty()) {
          ans[event.para] = *seg.begin();
        }
      } else {
        // 右端点事件，将区间长度从有序集合中移除
        int len = event.pos - event.para + 1;
        auto it = seg.find(len);
        seg.erase(it);
      }
    }
    return ans;
  }
};














