#include <iostream>



using namespace std;

static constexpr int mod = 1e9+7;

int main() {
	long long i = 0;
	long long n = 806166225460393;
	long long res = 1;
	while (i < n - 16) {
		res = (res * 400) % mod;
		res = (res * 400) % mod;
		res = (res * 400) % mod;
		res = (res * 400) % mod;
		i -= 16;
	}
	while (i < n - 4) {
		res = (res * 400) % mod;
		i -= 4;
	}
	while (i < n) {
		if (i % 2 == 0) {
			res = (res * 5) % mod;
		} else {
			res = (res * 4) % mod;
		}
		i++;
	}
	cout << "res:" << res << endl;

	return 0;
}







