

#include <queue>
#include <iostream>

using namespace std;



int main() {
	priority_queue<int> pq;

	for (int i = 0; i < 10; ++i) {
		pq.push(i);
	}
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}



}








