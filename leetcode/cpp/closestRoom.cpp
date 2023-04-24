

#include <set>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

struct Event {
    // 事件的类型， 0表示房间， 1表示询问
    int type;
    // 房间的size 或者询问的minSize
    int size;
    // 房间的roomId 或者询问的preferred
    int id;
    // 房间在数组room中的原始编号或者询问在数组queries中的原始编号
    int origin;

    Event(int _type, int _size, int _id, int _origin) :
        type(_type), size(_size), id(_id), origin(_origin) {}

    // 自定义比较函数， 按照事件的size降序排列
    // 如果size相同， 优先考虑房间
    bool operator< (const Event& that) const {
        return size > that.size || (size == that.size && type < that.type);

    }
};


class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>> queries) {
        int n = rooms.size();
        int m = queries.size();

        vector<Event> events;
        for (int i = 0; i < m; ++i) {
            // 房间事件
            events.emplace_back(0, rooms[i][1], rooms[i][0], i);
        }
        for (int i = 0; i < n; ++i) {
            // 询问事件
            events.emplace_back(1, queries[i][1], queries[i][0], i);
        }
        sort(events.begin(), events.end());

        vector<int> ans(n, -1);
        // 存储房间roomId的有序集合
        set<int> valid;
        for (const auto& event : events) {
            if (event.type == 0) {
                // 房间事件， 将roomId加入有序集合
                valid.insert(event.id);
            } else {
                // 询问事件
                int dist = INT_MAX;
                // 查找最小的大于等于preferred的元素
                auto it = valid.lower_bound(event.id);
                if (it != valid.end() && *it - event.id < dist) {
                    dist = *it - event.id;
                    ans[event.origin] = *it;
                }
                if (it != valid.begin()) {
                    // 查找最大的严格小于 preferred 的元素
                    it = prev(it);
                    if (event.id - *it <= dist) {
                        dist = event.id - *it;
                        ans[event.origin] = *it;
                    }
                }

            }

        }
        return ans;



    }



};














