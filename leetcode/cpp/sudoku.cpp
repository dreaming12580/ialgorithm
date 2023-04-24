const int N = 9;
int num[N][N];
bool flag;

int main() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> num[i][j];
		}
	}
	dfs(0);
	return 0;
}

void dfs(int n) {
	if (n == 81) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 8; ++j) {
				cout << num[i][j] << ' ';
			}
			cout << num[i][8] << endl;
		}
		flag = true;
		return;
	}
	int h = n / 9;
	int l = n % 9;
	if (num[h][l] == 0) {
		for (int i = 1; i <= 9; ++i) {
			num[h][l] = i;
			if (check(n)) {
				dfs(n + 1);
				if (flag) {
					return;
				}
			}
		}
		num[h][l] = 0;
	} else {
		dfs(n + 1);
	}
}

bool check(int n) {
	int h = n / 9;
	int l = n % 9;
	for (int i = 0; i < 9; ++i) {
		if (i != h && num[i][l] == num[h][l]) {
			return false;
		}
	}
	for (int j = 0; j < 9; ++j) {
		if (j != l && num[h][j] == num[h][l]) {
			return false;
		}
	}
	for (int i = h / 3 * 3; i < h / 3 * 3 + 3; ++i) {
		for (int j = l / 3 * 3; j < l / 3 * 3 + 3; ++j) {
			if ((i != h || j != l) && num[i][j] == num[h][l]) {
				return false;
			}
		}
	}



	return true;
}














