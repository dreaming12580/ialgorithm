
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string maximumNumber(string num, vector<int>& change) {
		auto left = find_if(num.begin(), num.end(), [&](char ch) -> bool { 
			int number = ch - '0';
			return change[number] > number;
		});

		auto right = find_if(left, num.end(), [&](char ch) -> bool { 
			int number = ch - '0';
			return change[number] < number;
		});

		for_each(left, right, [&](char& ch) -> void { 
			ch = '0' + change[ch - '0'];
		});

		return num;
	}
};











