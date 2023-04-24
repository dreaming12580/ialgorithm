
class Solution {
private:
	ListNode *head;

public:
	Solution(ListNode *head) {
		this->head = head;
	}

	int getRandom() {
		int i = 1, ans = 0; 
		for (auto node = head; node; node = node->next) {
			// 1 / i 的概率选中 (替换为答案)
			if (rand() % i == 0) {
				ans = node->val;
			}
			++i;
		}
		return ans;
	}
};













