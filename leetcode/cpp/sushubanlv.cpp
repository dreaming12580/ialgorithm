#include <iostream>

using namespace std;

// 二分图， 匈牙利算法， 增广路


bool isprime(int i) {
	for (int j = 2; j * j <= i; ++j) {
		if (i % j == 0) {
			return false;
		}
	}
	return true;
}

bool find(const int &n, vector<vector<bool>> &map, vector<int> &match, vector<bool> &visit) {
	for (int i = 0; i < match.size(); ++i) {
		if (!visit[i] && map[i][n]) {
			visit[i] = true; // 对于每个 u 节点， visit都会进行初始化，这里是避免遍历死循环
			if (match[i] == -1 || find(match[i], map, match, visit)) {
				match[i] = n;
				return true;
			}
		}
	}
	return false;
}


int main() {
	int n;
	cin >> n;
	int k = 0;
	vector<int> even, odd;
	int count = 0;
	while (n--) {
		cin >> k;
		if (k % 2 == 0) {
			odd.push_back(k);
		} else {
			even.push_back(k);
		}
	}
	if (odd.empty() || even.empty()) {
		cout << count << endl;
		return 0;
	}

	vector<vector<bool>> map(even.size(), vector<bool>(odd.size(), false));
	for (int i = 0; i < even.size(); ++i) {
		for (int j = 0; j < odd.size(); ++j) {
			if (isprime(even[i] + odd[j])) {
				map[i][j] = true;
			}
		}
	}

	// match 偶数的大小， 但是里面元素都是奇数 odd
	vector<int> match(even.size(), -1);
	for (int i = 0; i < odd.size(); ++i) {
		vector<bool> visit(even.size(), false);
		if (find(i, map, match, visit)) {
			++count;
		}
	}
	cout << count << endl;
	return 0;
}















