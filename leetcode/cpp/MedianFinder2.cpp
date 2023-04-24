#include <multiset>

using namespace std; 


class MedianFinder {
private:
	multiset<int> nums; 
	multiset<int>::iterator left, right; 

public:
	MedianFinder() : left(nums.end()), right(nums.end()) {}

	void addNum(int num) {
		const size_t n  = nums.size();
		nums.insert(num);
		if (!n) {
			left = right = nums.begin();
		} else if (n & 1) {
			if (num < * left) {
				--left;
			} else {
				++right;
			}
		} else {
			if (*left < num && num < * right) {
				++left;
				--right;
			} else if (num > *right) {
				++left;
			} else {
				--right;
				left = right;
			}
		}
	}

	double findMedian() {
		return (*left / 2. 0 + *right / 2.0);
	}



}
















