




// 平衡二叉搜索树，
// AVL树
// 红黑树
// Treap 
// SBT

class BalancedTree {
private:
	struct BalancedNode {
		long long val;
		long long seed;
		int count;
		int size;
		BalancedNode* left;
		BalancedNode* right;

		BalancedNode(long long _val, long long _seed) : val(_val), seed(_seed), count(1), size(1), left(nullptr), right(nullptr) {}

		BalancedNode* left_rotate() {
			int prev_size = size;
			int curr_size = (left ? left->size : 0) + (right->left ? right->left->size : 0) + count;
			BalancedNode* root = right;
			right = root->left;
			root->left = this;
			root->size = prev_size;
			size = curr_size;
			return root;
		}

		BalancedNode* right_rotate() {
			int prev_size = size;
			int curr_size = (right ? right->size : 0) + (left->right ? left->right->size : 0) + count;
			BalancedNode* root = left;
			left = root->right;
			root->right = this;
			root->size = prev_size;
			size = curr_size;
			return root;
		}
	};

private:
	BalancedNode* root;
	int size;
	mt19937 gen;
	uniform_int_distribution<long long> dis;

private:
	BalancedNode* insert(BalancedNode* node, long long x) {
		if (!node) {
			return new BalancedNode(x, dis(gen));
		}
		++node->size;
		if (x < node->val) {
			node->left = insert(node->left, x);
			if (node->left->seed > node->seed) {
				node = node->right_rotate();
			}
		} else if (x > node->val) {
			node->right = insert(node->right, x);
			if (node->right->seed > node->seed) {
				node = node->left_rotate();
			}
		} else {
			++node->count;
		}
		return node;
	}

public:
	BalancedTree(): root(nullptr), size(0), gen(random_device{}()), dis(LLONG_MIN, LLONG_MAX) {}

	long long get_size() const {
		return size;
	}

	void insert(long long x) {
		++size;
		root = insert(root, x);
	}

	long long lower_bound(long long x) const {
		BalancedNode* node = root;
		long long ans = LLONG_MAX;
		while (node) {
			if (x == node->val) {
				return x;
			}
			if (x < node->val) {
				ans = node->val;
				node = node->left;
			} else {
				node = node->right;
			}
		}
		return ans;
	}

	long long upper_bound(long long x) const {
		BalancedNode* node = root;
		long long ans = LLONG_MAX;
		while (node) {
			if (x < node->val) {
				ans = node->val;
				node = node->left;
			} else {
				node = node->right;
			}
		}
		return ans;
	}

	pair<int, int> rank(long long x) const {
		BalancedNode* node = root;
		int ans = 0;
		while (node) {
			if (x < node->val) {
				node = node->left;
			} else {
				ans += (node->left ? node->left->size : 0) + node->count;
				if (x == node->val) {
					return {ans - node->count + 1, ans};
				}
				node = node->right;
			}
		}
		return {INT_MIN, INT_MAX};
	}
};

class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		long long sum = 0;
		vector<long long> preSum = {0};
		for (int v : nums) {
			sum += v;
			preSum.push_back(sum);
		}

		BalancedTree* treap = new BalancedTree();
		int ret = 0;
		for (long long x : preSum) {
			long long numLeft = treap->lower_bound(x - upper);
			int rankLeft = (numLeft == LLONG_MAX ? treap->get_size() + 1 : treap->rank(numLeft).first);
			long long numRight = treap->upper_bound(x - lower);
			int rankRight = (numRight == LLONG_MAX ? treap->get_size() : treap->rank(numRight).first - 1);
			ret += (rankRight - rankLeft + 1);
			treap->insert(x);
		}
		return ret;
	}
};







