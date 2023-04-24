



class Solution {
public:
	const int MOD = 1e9 + 7;
	int gcd (int a, int b) {
		return b != 0 ? gcd(b, a % b) : a;
	}
	int lcm(int a, int b) {
		return a * b / gcd(a, b);
	}
	int nthMagicalNumber(int n, int a, int b) {
		long long l = min(a, b);
		long long r = (long long)n * min(a, b);
		int c = lcm(a, b);
		while (l <= r) {
			long long mid = (l + r) / 2;
			long long cnt = mid / a + mid / b - mid / c;
			if (cnt >= n) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return (r + 1) % MOD;
	}
};

















