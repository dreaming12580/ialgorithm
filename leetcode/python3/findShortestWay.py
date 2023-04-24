
class Solution:
  def findShortestWay(self, maze: List[List[int]], ball: List[int], hole: List[int]) -> str:
    directions = [(-1, 0, 'u'), (0, 1, 'r'), (0, -1, 'l'), (1, 0, 'd')]
    m = len(maze)
    n = len(maze[0])
    # 构造队列， 并将起始位置包含其中
    queue = [(ball[0], ball[1])]
    
    distance = [[float('inf') * n for _ in range(m)]]
    string = [["impossible"] * n for _ in range(m)]
    # 对起点的 distance 和 string 进行初始化
    distance[ball[0]][ball[1]] = 0
    string[ball[0]][ball[1]] = ""

    while queue:
      i, j = queue.pop(0);
      # 对四个方向进行遍历， letter 保存了操作对应的字符
      for dx, dy, letter in directions:
        x, y, step, word = i + dx, j + dy, distance[i][j], string[i][j]
        while 0 <= x < m and 0 <= y < n and
            maze[x][y] == 0 and
            (x - dx != hole[0] or y - dy != hole[1]):
          







