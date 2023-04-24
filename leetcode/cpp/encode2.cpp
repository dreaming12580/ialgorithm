#include <bits/stdc++.h>

using namespace std;


string encode(string s) {
  vector<vector<string>> d(s.size(), vector<string>(s.size(), ""));
  for (int len = 1; len <= s.size(); ++len) {
    for (int i = 0; i + len <= s.size(); ++i) {
      const int j = i + len - 1;
      string& ans = d[i][j];
      ans = s.substr(i, len);
      if (len >= 5) {
        int p = (ans + ans).find(ans, 1);
        if (p < ans.size()) {
          ans = to_string(ans.size() / p) + "[" + d[i][i + p - 1] + "]";
        }
        for (int k = i; k < j; ++k) {
          if (d[i][k].size() + d[k + 1][j].size() < ans.size()) {
            ans = d[i][k] + d[k + 1][j];
          }
        }
      }
    }
  }
  return d[0][s.size() - 1];
}












