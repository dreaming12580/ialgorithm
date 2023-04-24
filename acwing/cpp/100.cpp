#include <iostream>
#include <algorithm>

using namespace std;


const int N = 1e5 +10;
int b[N], a[N];

long long pos, neg;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = a[i] - a[i - 1];
  }
  for (int i = 2; i <= n; ++i) {
    if (b[i] > 0) {
      pos += b[i];
    } else {
      neg -= b[i];
    }
  }
  cout << min(pos, neg) + abs(pos - neg) << endl;
  cout << abs(pos - neg) + 1;
}














