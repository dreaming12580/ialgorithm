#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
	const int mod = 1e9 + 9;
	const int base = 113;

	long long qPow(long long x, long long n) {
		long long ret = 1;
		while (n) {
			if (n & 1) {
				ret = ret * x % mod;
			}
			x = x * x % mod;
			n >>= 1;
		}
		return ret;
	}

	bool check(vector<int>& A, vector<int>& B, int len) {
		long long hashA = 0;
		for (int i = 0; i < len; ++i) {
			hashA = (hashA * base + A[i]) % mod;
		}
		unordered_set<long long> bucketA;
		bucketA.insert(hashA);
		long long mult = qPow(base, len - 1);
		for (int i = len; i < A.size(); ++i) {
			hashA = ((hashA - A[i - len] * mult % mod + mod) % mod * base + A[i]) % mod;
			bucketA.insert(hashA);
		}
		long long hashB = 0;
		for (int i = 0; i < len; ++i) {
			hashB = (hashB * base + B[i]) % mod;
		}
		if (bucketA.count(hashB)) {
			return true;
		}
		for (int i = len; i < B.size(); ++i) {
			hashB = ((hashB - B[i - len] * mult % mod + mod) % mod * base + B[i]) % mod;
			if (bucketA.count(hashB)) {
				return true;
			}
		}
		return false;
	}

	int findLength(vector<int>& A, vector<int>& B) {
		int left = 1, right = min(A.size(), B.size()) + 1;
		while (left < right) {
			int mid = (left + right) >> 1;
			if (check(A, B, mid)) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		return left - 1;
	}

};
























