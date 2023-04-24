








#130.#########################

void solve(char[][] board) {
  if (board.length == 0) return;

  int m = board.length;
  int n = board[0].length;

  //给dummy留一个额外位置
  UF uf = new UF(m * n + 1);
  int dummy = m * n;
  // 将首列和末列的O 与dummy连通
  for (int i = 0; i < m; i++) {
    if (board[i][0] = 'O') {
      uf.union(i * n, dummy);
    }
    if (board[i][n - 1] == 'O') {
      uf.union(i * n + n - 1, dummy);
    }
  }

  // 将首行和末行的O 与 dummy连通
  for (int j = 0; j < n; j++) {
    if (board[0][j] == 'O') {
      uf.union(j, dummy);
    }
    if (board[m - 1][j] == 'O') {
      uf.union(n * (m - 1) + j, dummy);
    }
  }
  // 方向数组d 是上下左右搜索的常用方法
  int[][] d = new int[][]{{1,0}, {0, 1}, {-1,0}, {0, -1}};
  for (int i = 1; i < m - 1; i++) {
    for (int j = 1; j < n - 1; j++) {
      if (board[i][j] == 'O') {
        // 将此O 与上下左右的O连通
        for (int k = 0; k < 4; k++) {
          int x = i + d[k][0];
          int y = j + d[k][1];
          if (board[x][y] == 'O') {
            uf.union(x * n + y, i * n + j);
          }
        }
      }
    }
  }

  // 所有不和 dummy连通的O, 都要被替换
  for (int i = 1; i < m - 1; i++) {
    for (int j = 1; j < n - 1; j++) {
      if (!uf.connected(dummy, i * n + j)) {
        board[i][j] = 'X'
      }
    }
  }
}








#990################################

boolean equationsPossible(String[] equations) {
  // 26个英文字母
  UF uf = new UF(26);
  // 先让相等的字母形成连通分量
  for (String eq : equations) {
    if (eq.charAt(1) == '=') {
      char x = eq.charAt(0);
      char y = eq.charAt(3);
      uf.union(x - 'a', y - 'a');
    }
  }
  // 检查不等关系是否打破相等关系的连通性
  for (String eq : equations) {
    if (eq.charAt(1) == '!') {
      char x = eq.charAt(0);
      char y = eq.charAt(3);
      // 如果相等关系成立， 就是逻辑冲突
      if (uf.connected(x - 'a', y - 'a')) {
        return false;
      }
    }
  }
  return true;
}






