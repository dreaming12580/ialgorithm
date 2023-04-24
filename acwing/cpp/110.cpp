
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, int> PII;
const int N = 2510;

int n, m;
PII cows[N];

int main() {
  cin >> n >> m;
  map<int, int> spfs;
  for (int i = 0; i < n; ++i) {
    cin >> cows[i].first >> cows[i].second;
  }
  for (int i = 0; i < m; ++i) {
    int spf, cover;
    cin >> spf >> cover;
    spfs[spf] += cover;
  }
  sort(cows, cows + n);
  int res = 0;
  spfs[0] = spfs[1001] = n;
  for (int i = n - 1; i >= 0; --i) {
    auto spf = spfs.upper_bound(cows[i].second);
    spf--;
    if (spf->first >= cows[i].first) {
      ++res;
      if (--spf->second == 0) {
        spfs.erase(spf);
      }
    }
  }
  cout << res << endl;
  return 0;
}







