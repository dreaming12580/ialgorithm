#include <iostream>


using namespace std;


class Solution {
private:
	static constexpr int mod = 1e9 + 7;

public:
	int countGoodNumbers(long long n) {
		auto quickmul = [](int x, long long y) -> int {
			int ret = 1, mul = x;
			while (y > 0) {
				if (y % 2 == 1) {
					ret = (long long)ret * mul % mod;
				}
				mul = (long long)mul * mul % mod;
				y /= 2;
			}
			return ret;
		};
		return quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % mod;
	}
};


int main() {
	long long n = 806166225460393;
	Solution s;
	cout << s.countGoodNumbers(n) << endl;
	return 0;
}



















