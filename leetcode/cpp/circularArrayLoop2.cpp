#include <vector> 



using namespace std;



class Solution {
public:
	bool circularArrayLoop(vector<int>& nums) {
		int n = nums.size();
		auto next = [&] (int cur) { 
			// 保证返回值在 [0, n) 中
			return ((cur + nums[cur]) % n + n) % n;
		};

		for (int i = 0; i < n; ++i) {
			if (!nums[i]) {
				continue;
			}
			int slow = i, fast = next(i);
			// 判断非零且方向相同
			while (nums[slow] * nums[fast] > 0 && nums[slow] * nums[next(fast)] > 0) {
				if (slow == fast) {
					if (slow != next(slow)) {
						return true;
					} else {
						break;
					}
				}
				slow = next(slow);
				fast = next(next(fast));
			}
			int add = i;
			// 路径上的点不为0 并且方向不相反
			while (nums[add] * nums[next(add)] > 0) {
				int tmp = add;
				add = next(add);
				nums[tmp] = 0;
			}

		}







	}










};









