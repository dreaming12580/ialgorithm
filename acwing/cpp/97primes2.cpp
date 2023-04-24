#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

const int mod = 9901;
int A, B;

unordered_map<int, int> primes;

// 试除法质因子分解
void divide(int n) {
  for (int i = 2; i <= n/ i; ++i) {
    if (n % i == 0) {
      while (n % i == 0) {
        primes[i]++;
        n /= i;
      }
    }
  }
  if (n > 1) {
    primes[n]++;
  }
}

// 快速幂
int qmid(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = (ll)res * a % mod;
    }
    a = (ll) a * a % mod;
    b >>= 1;
  }
  return res;
}

// p0 + ... + pk - 1
int sum(int p, int k) {
  if (k == 1) {
    return 1;
  }
  if (k % 2 == 0) {
    return (ll)(qmid(p, k / 2) + 1) * sum(p, k / 2) % mod;
  }
  return (qmid(p, k - 1) + sum(p, k - 1)) % mod;
}

int main() {
  cin >> A >> B;
  
  // 对 A 分解质因子
  divide(A);

  int res = 1;
  for (auto it : primes) {
    // p 是质因子， k 是质因子的次数
    int p = it.first, k = it.second * B;
    // res 要乘上每一项， 注意这里是 k + 1
    res = (ll)res * sum(p, k + 1) % mod;
  }
  if (!A) {
    res = 0;
  }
  cout << res << endl;
  return 0;
}




