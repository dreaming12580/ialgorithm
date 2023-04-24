#include <string>


using namespace std;

class Solution {
public:
	bool oneEditAway(string first, string second) {
		int m = first.size(), n = second.size();
		if (n - m == 1) {
			return oneInsert(first, second);
		} else if (m - n == 1) {
			return oneInsert(second, first);
		} else if (m == n) {
			bool foundDifference = false;
			for (int i = 0; i < m; ++i) {
				if (first[i] != second[i]) {
					if (!foundDifference) {
						foundDifference = true;
					} else {
						return false;
					}
				}
			}
			return true;
		}  
		return false;
	}

	bool oneInsert(string shorter, string longer) {
		int slen = shorter.size(), llen = longer.size();
		int sidx = 0, lidx = 0;
		while (sidx < slen && lidx < llen) {
			if (shorter[sidx] == longer[lidx]) {
				sidx++;
			}
			lidx++;
			if (lidx - sidx > 1) {
				return false;
			}
		}
		return true;
	}
};









