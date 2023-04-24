#include <cstdlib>


struct ListNode {
	int val; 
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
	ListNode *head;

public:
	Solution(ListNode *head) {
		this->head = head;
	}

	int get Random() {
		int i = 1, ans = 0;
		for (auto node = head; node; node = node->next) {
			if (rand() % i == 0) {
				// 1 / i 的概率选中 (替换为答案)
				ans = node->val;
			}
			++i;
		}
		return ans;
	}
};







