#include <bits/stdc++.h>

using namespace std;

string encode(string s) {
  vector<vector<string>> d(s.size(), vector<string>(s.size(), ""));
  return dfs(s, 0, s.size() - 1, d);
}


string dfs(const string s, int i, int j, vector<vector<string>>& d) {
  if (i > j) {
    return "";
  }
  string& ans = d[i][j];
  if (ans.size()) {
    return ans;
  }
  int len = j - i + 1;
  ans = s.substr(i, len);
  if (len < 5) {
    return ans;
  }
  int p = (ans + ans).find(ans, 1);
  if (p < len) {
    ans = to_string(len / p) + "[" + dfs(s, i, i + p - 1, d) + "]";
  }
  for (int k = i; k < j; ++k) {
    string c = dfs(s, i, k, d);
    string e = dfs(s, k + 1, j, d);
    if (c.size() + e.size() < ans.size()) {
      ans = c + e;
    }
  }
  return ans;
}










