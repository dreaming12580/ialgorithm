#include <bits/stdc++.h>

using namespace std;

class NumMatrix {
public:
  int n, m;
  vector<vector<int>> vec;

  int lowbit(int x) {
    return x & -x;
  }

  NumMatrix(vector<vector<int>>& matrix) {
    m = matrix.size();
    n = matrix[0].size();
    vec = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        vec[i + 1][j + 1] += matrix[i][j];
        int jj = j + 1 + lowbit(j + 1);
        if (jj <= n) {
          vec[i + 1][jj] += vec[i + 1][j + 1];
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int ii = i + 1 + lowbit(i + 1);
        if (ii <= m) {
          vec[ii][j + 1] += vec[i + 1][j + 1];
        }
      }
    }
  }

  void update(int row, int col, int val) {
    int add = val - sumRegion(row, col, row, col);
    ++row, ++col;
    while (row <= m) {
      int c = col;
      while (c <= n) {
        vec[row][c] += add;
        c += lowbit(c);
      }
      row += lowbit(row);
    }
  }

  int get(int row, int col) {
    if (row < 0 || col < 0) {
      return 0;
    } 
    int ans = 0;
    while (row) {
      int c = col;
      while (c) {
        ans += vec[row][c];
        c -= lowbit(c);
      }
      row -= lowbit(row);
    }
    return ans;
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    ++row1, ++col1, ++row2, ++col2;
    return get(row2, col2) - get(row1 - 1, col2) - 
          get(row2, col1 - 1) + get(row1 - 1, col1 - 1);
  }
};







