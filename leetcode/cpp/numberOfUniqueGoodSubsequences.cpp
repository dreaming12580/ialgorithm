#include <string>


using namespace std;



class Solution {
private:
	static constexpr int mod = 1e9 + 7;

public:
	int numberOfUniqueGoodSubSequences(string binary) {
		int even = 0, odd = 0;
		for (char ch : binary) {
			if (ch == '0') {
				even = (even + odd) % mod;
			} else {
				odd = (even + odd + 1) % mod;
			}
		}
		int ans = (even + odd + (binary.find('0') != string::npos)) % mod;
		return ans;
	}








};

















