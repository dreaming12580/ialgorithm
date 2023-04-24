#include <vector>
#include <iostream>
#include <bitset>
#include <climits>

using namespace std;



class Solution {
public:
	int minSessions(vector<int>& tasks, int sessionTime) {
		const int n = tasks.size();
		vector<int> valid(1 << n);
		for (int mask = 1; mask < (1 << n); ++mask) {
			int needTime = 0;
			for (int i = 0; i < n; ++i) {
				if (mask & (1 << i)) {
					needTime += tasks[i];
				}
			}
			if (needTime <= sessionTime) {
				valid[mask] = true;
			}
		}
		vector<int> f(1 << n, INT_MAX / 2);  
		f[0] = 0;
		for (int mask = 1; mask < (1 << n); ++mask) {
			cout << "mask: " << std::bitset<10>(mask) << endl;
			for (int subset = mask; subset; subset = (subset - 1) & mask) {
				cout << " " << std::bitset<10>(subset);
				if (valid[subset]) {
					f[mask] = min(f[mask], f[mask ^ subset] + 1);
				}
			}
			cout << endl;
		}
		return f[(1 << n) - 1];
	}
};


int main() {
	vector<int> tasks = {2, 3, 3, 4, 4, 4, 5, 6, 7, 10};
	int sessionTime = 12;

	Solution s;
	cout << "s: " << s.minSessions(tasks, sessionTime) << endl;


}












