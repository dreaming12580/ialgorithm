#include <string>

using namespace std;

class Solution {
private:
	bool areAllZeros(vector<int>& counts) {
		int n = counts.size();  
		for (int i = 0; i < n; ++i) {
			if (counts[i] != 0) {
				return false;
			}
		}
		return true;
	}

public:
	bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size()) {
			return false;
		}
		vector<int> counts(26, 0);
		for (int i = 0; i < s1.size(); ++i) {
			--counts[s1[i] - 'a'];
			++counts[s2[i] - 'a'];
		}
		if (areAllZeros(counts)) {
			return true;
		}
		for (int i = s1.size(); i < s2.size(); ++i) {
			++counts[s2[i] - 'a'];
			--counts[s2[i - s1.size()] - 'a'];
			if (areAllZeros(counts)) {
				return true;
			}
		}
		return false;
	}
};









