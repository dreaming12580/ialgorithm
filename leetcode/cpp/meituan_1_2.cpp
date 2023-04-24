#include <cstdio>
#include <cstring>
#include <map>
#include <set>

int prefix[50050];
std::map<int, int> map;
std::set<int> bound;

int main() {
	int n;
	scanf("%d", &n);
	int w;
	memset(prefix, 0, sizeof(prefix));  
	for (int i = 0; i < n; ++i) {
		scanf("%d", &w);
		prefix[i + 1] = prefix[i] + w;
	}
	int pos;
	bound.insert(0);
	bound.insert(n + 1);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &pos);
		auto idx = bound.lower_bound(pos);
		// 由于set的迭代器只能自减， 所以先给 right 赋值
		int right = *idx, left = *(--idx);
		int seg = prefix[right - 1] - prefix[left];
		if (map.find(seg) != map.end()) {
			if (map[seg] == 1) {
				map.erase(seg);
			} else {
				map[seg]--;
			}
		}
		int left_sum = prefix[pos - 1] - prefix[left];
		int right_sum = prefix[right - 1] - prefix[pos];
		bound.insert(pos);
		map[left_sum]++;
		map[right_sum]++;
		printf("%d\n", map.rbegin()->first);


	}



}

















