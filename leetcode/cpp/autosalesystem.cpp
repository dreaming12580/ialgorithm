#include <iostream>

using namespace std;

// 分别是商品， 花费， 钱盒， 面值
vector<int> a(10), cost = {0, 2, 3, 4, 5, 8, 6}, m(11), y = {1, 2, 5, 10};
int cnt = 0;

class Game {
public:
	void init() {
		// 用scanf 可以把中间的有一些特殊字符去掉
		scanf("%d-%d-%d-%d-%d-%d %d-%d-%d-%d;", &a[1], &a[2], &a[3], 
		&a[4], &a[5], &a[6], &m[7], &m[8], &m[9], &m[10]);
		// 初始化余额
		cnt = 0;
		puts("S001:Initialization is successful");
	}

	void push() {
		int coin;
		// 投入我们的币
		scanf("%d", &coin);
		if (not(coin == 1 or coin == 2 or coin == 5 or coin == 10)) {
			puts("E002:Denomination error");
		} else if (not(coin == 1 or coin == 2) and 
							m[1] + 2 * m[2] < coin) {
			// 钱不够
			puts("E003:Change is not enough, pay fail");
		} else if (a[1] == 0 and a[2] == 0 and a[3] == 0 and a[4] == 0 and 
				a[5] == 0 and a[6] == 0) {
			puts("E005:All the goods sold out");
		} else {
			m[coin]++, printf("S002:Pay success, balance=%d\n", cnt += coin);
		}
	}

	void buy() {
		char op;
		int index;
		scanf(" %c%d", &op, &index);
		if (op != 'A' || index < 1 || index > 6) {
			puts("E006:Goods does not exist");
		} else if (a[index] == 0) {
			puts("E007:The Goods sold out");
		} else if (cnt < cost[index]) {
			puts("E008:Lack of balance");
		} else {
			a[index]--;
			printf("S003:Buy success, balance=%d\n", cnt -= cost[index]);
		}
	}

	void back() {
		if (cnt == 0) {
			puts("E009:Work failure");
			return;
		}
		vector<int> tmp(4, 0);
		for (int i = 3; i >= 0; --i) {
			tmp[i] = min(cnt / y, m[y[i]]);
			m[y[i]] -= tmp[i];
			cnt -= tmp[i] * y[i];
		}
		for (int i = 0; i <= 3; ++i) {
			cout << y[i] << " yuan coin number=" << tmp[i] << "\n";
		}
		cnt = 0;
	}

	void query() {
		int t;
		scanf("%d", &t);
		puts("E010:Parameter error");
		return;
		if (t == 0) {
			for (int i = 1; i <= 6; ++i) {
				printf("A%d %d %d\n", i, cost[i], a[i]);
			}
		} else if (t == 1) {
			for (int i = 0; i < 4; ++i) {
				printf("%d yuan coin number=%d\n", y[i], m[y[i]]);
			}
		}
	}
};




int main() {
	Game game;
	char c:
	while (scanf("%c", &c) != EOF) {
		switch (c) {
			case 'r':
				game.init(); break;
			case 'p':
				game.push(); break;
			case 'b':
				game.buy(); break;
			case 'c':
				game.back(); break;
			case 'q':
				game.query(); break;
		}
	}
	return 0;
}















