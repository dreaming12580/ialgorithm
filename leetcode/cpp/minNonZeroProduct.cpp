



class Solution {
private:
	static constexpr int mod = 1e9 + 7;

	long long qpow(long long x, long long n) {
		long long res = 1;
		for (x %= mod; n > 0; n >>= 1) {
			if (n & 1) {
				res = res * x % mod;
			}
			x = x * x % mod;
		}
		return res;
	}

public:

	int minNonZeroProduct(int p) {
		return ((1LL << p) - 1) % mod * pow((1LL << p) - 2, (1LL << (p - 1)) - 1) % mod;
	}
};














