#include <string>
#include <unordered_set>



using namespace std;


string countDigits(int n) {
	string cnt(10, 0);
	while (n) {
		++cnt[n % 10];
		n /= 10;
	}
	return cnt;
}

unordered_set<string> powerOf2Digits;

int init = []() {
	for (int i = 1; i <= 1e9; i <<= 1) {
		powerOf2Digits.insert(countDigits(i));
	}
	return 0;
}();

class Solution {
public:
	bool reorderedPowerOf2(int n) {
		return powerOf2Digits.count(countDigits(n));
	}
};


















