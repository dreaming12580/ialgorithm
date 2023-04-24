
class Solution {
public:
  int minKnightMoves(int x, int y) {
    if (x == 0 && y == 0) {
      return 0;
    }
    // 都是关于(0, 0)对称
    x = abs(x);
    y = abs(y);
    // --------------记忆化 bfs ---------------
    queue<pair<int, int>> q;
    set<pair<int, int>> visited;
    q.push({0, 0});
    visited.insert({0, 0});
    int step = 0;

    while (true) {
      int cur_len = q.size();
      step++;
      while(cur_len--) {
        auto [x0, y0] = q.front(); q.pop();
        for (auto& [dx, dy] : vector<pair<int,int>>{{-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {2, 1}, {2, -1}}) {
          int nx = x0 + dx;
          int ny = y0 + dy;
          if (visited.find({nx, ny}) == visited.end()) {
            if (-5 <= nx && nx <= x + 5 && -5 <= ny && ny <= y + 5) {
              if (x == nx && y == ny) {
                return step;
              }
              q.push({nx, ny});
              visited.insert({nx, ny});
            }
          }
        }
      }
    }
    return 0;
  }
};




















