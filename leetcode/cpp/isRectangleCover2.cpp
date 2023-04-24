typedef pair<int, int> Point;

class Solution {

public:
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    long area = 0;
    int minX = rectangles[0][0], minY = rectangles[0][1], 
        maxX = rectangles[0][2], maxY = rectangles[0][3];
    map<Point, int> cnt;
    for (auto& rect : rectangles) {
      int x = rect[0], y = rect[1], a = rect[2], b = rect[3];
      area += (long)(a - x) * (b - y);

      minX = min(minX, x);
      minY = min(minY, y);
      maxX = max(maxX, a);
      maxY = max(maxY, b);

      Point p1({x, y});
      Point p2({x, b});
      Point p3({a, y});
      Point p4({a, b});

      cnt[p1] += 1;
      cnt[p2] += 1;
      cnt[p3] += 1;
      cnt[p4] += 1;
    }
    Point left_lower({minX, minY});
    Point left_high({minX, maxY});
    Point right_lower({maxX, minY});
    Point right_high({maxX, maxY});
    if (area != (long long)(maxX - minX) * (maxY - minY) ||
        !cnt.count(left_lower) || 
        !cnt.count(left_high) ||
        !cnt.count(right_lower) ||
        !cnt.count(right_high)) {
      return false;
    }

    cnt.erase(left_lower);
    cnt.erase(left_high);
    cnt.erase(right_lower);
    cnt.erase(right_high);

    for (auto& entry : cnt) {
      int value = entry.second;
      if (value != 2 && value != 4) {
        return false;
      }
    }
    return true;
  }
};







