
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;



class Solution {










};

string convert(int n) {
	vector<int> res;
	while (n) {
		if (n & 1) {
			res.push_back(1);
		} else {
			res.push_back(0);
		}
		n = (n - 1) & n;
	}
	reverse(res.begin(), res.end());
	string t;
	for (auto item : res) {
		t += item;
	}
	reverse(t.begin(), t.end());
	return t;
}

int main() {
	int m = 5;
	int j = (1 << m) - 1;
	cout << convert(j) << endl;
	for (int s = j; s != 0; s = ((s - 1) & j)) {
		cout << " " << convert(s) << endl;
	}



	return 0;
}




