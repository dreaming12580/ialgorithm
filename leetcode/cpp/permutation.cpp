




#include <vector>
#include <string>
#include <algorithm>


using namespace std;




class Solution {

public:
	bool nextPermutation(string& s) {
		int i = s.size() - 2;
		while (i >= 0 && s[i] >= s[i + 1]) {
			i--;
		}
		if (i < 0) {
			return false;
		}
		int j = s.size() - 1;
		while (j >=0 && s[i] >= s[j]) {
			j--;
		}
		swap(s[i], s[j]);
		reverse(s.begin() + i + 1, s.end());
		return true;
	}




	vector<string> permutation(string s) {
		vector<string> ret;
		sort(s.begin(), s.end());
		do {
			ret.push_back(s);
		} while (nextPermutation(s));
		return ret;
	}






};

















