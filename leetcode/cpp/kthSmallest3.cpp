
#include <vector>

using namespace std;

// 平衡二叉搜索树结点
struct Node {
	int val;
	Node* parent;
	Node* left;
	Node* right;
	int size;
	int height;

	Node(int val) {
		this->val = val;
		this->parent = nullptr;
		this->left =nullptr;
		this->right = nullptr;
		this->height = 0;		// 结点高度，以 node为根节点的子树的高度
		this->size = 1;			// 结点元素数， 以node为根节点的子树的节点总数
	}

	Node(int val, Node* parent) {
		this->val = val;
		this->parent = parent;
		this->left = nullptr;
		this->right = nullptr;
		this->height = 0;
		this->size = 1;
	}

	Node(int val, Node* parent, Node* left, Node* right) {
		this->val = val;
		this->parent = parent;
		this->left = left;
		this->right = right;
		this->height = 0;
		this->size = 1;
	}
};

// 平衡二叉搜索树 (AVL树) : 允许重复值
class AVL {
public:
	AVL(vector<int>& vals) {
		if (!vals.empty()) {
			root = build(vals, 0, vals.size() - 1, nullptr);
		}
	}

	// 根据 vals[l:r] 构造平衡二叉搜索树 -> 返回根节点
	Node* build(vector<int>& vals, int l, int r, Node* parent) {
		int m = (l + r) >> 1;
		Node* node = new Node(vals[m], parent);
		if (l <= m - 1) {
			node->left = build(vals, l, m - 1, node);
		}
		if (m + 1 <= r) {
			node->right = build(vals, m + 1, r, node);
		}
		recompute(node);
		return node;
	}

	// 返回二叉搜索树中第 k 小的元素
	int kthSmallest(int k) {
		Node* node = root;
		while (node != nullptr) {
			int left = getSize(node->left);
			if (left < k - 1) {
				node = node->right;
				k -= left + 1;
			} else if (left == k - 1) {
				break;
			} else {
				node = node->left;
			}
		}
		return node->val;
	}

	void insert(int v) {
		if (root == nullptr) {
			root = new Node(v);
		} else {
			// 计算新结点的添加位置
			Node* node = subtreeSearch(root, v);
			bool isAddLeft = v <= node->val;	// 是否将新结点添加到 node的左子结点
			if (node->val == v) {
				// 如果值为 v 的结点已存在
				if (node->left != nullptr) {
					// 值为 v 的结点存在左子结点， 则添加到其左子树的最右侧
					node = subtreeLast(node->left);
					isAndLeft = false;
				} else {
					// 值为 v 的结点不存在左子结点， 则添加到其左子结点
					isAddLeft = true;
				}
			}
			
			// 添加新结点
			Node* leaf = new Node(v, node);
			if (isAddLeft) {
				node->left = leaf;
			} else {
				node->right = leaf;
			}
			rebalance(leaf);
		}
	}

	// 删除值为 v 的结点 -> 返回是否成功删除结点
	bool Delete(int v) {
		if (root == nullptr) {
			return false;
		}
		Node* node = subtreeSearch(root, v);
		if (node->val != v) {
			// 没有找到需要删除的结点
			return false;
		}

		// 处理当前结点既有左子树也有右子树的情况
		// 若左子树比右子树高度低， 则将当前结点替换为右子树最左侧的结点， 并移除右子树最左侧的结点
		// 若右子树比左子树高度低， 则将当前结点替换为左子树最右侧的结点， 并移除左子树最右侧的结点
		if (node->left != nullptr && node->right != nullptr) {
			Node* replacement = nullptr;
			if (node->left->height <= node->right->height) {
				replacement = subtreeFirst(node->right);
			} else {
				replacement = subtreeLast(node->left);
			}
			node->val = replacement->val;
			node = replacement;
		}

		Node* parent = node->parent;
		Delete(node);
		rebalance(parent);
		return true;
	}

private:
	Node* root;

	// 删除结点 p 并用它的子结点代替它， 结点 p 至多只能有 1个子结点
	void Delete(Node* node) {
		if (node->left != nullptr && node->right != nullptr) {
			return;
		}
		Node* child = node->left != nullptr ? node->left : node->right;
		if (child != nullptr) {
			child->parent = node->parent;
		}
		if (node == root) {
			root = child;
		} else {
			Node* parent = node->parent;
			if (node == parent->left) {
				parent->left = child;
			} else {
				parent->right = child;
			}
		}
		node->parent = node;
	}

	// 在以 node 为根结点的子树中搜索值为 v 的结点， 
	// 如果没有值为 v 的结点，则返回值为 v 的结点应该在的位置的父结点
	Node* subtreeSearch(Node* node, int v) {
		if (node->val < v && node->right != nullptr) {
			return subtreeSearch(node->right, v);
		} else if (node->val > v && node->left != nullptr) {
			return subtreeSearch(node->left, v);
		} else {
			return node;
		}
	}

	// 重新计算 node 结点的高度和元素数
	void recompute(Node* node) {
		node->height = 1 + max(getHeight(node->left), getHeight(node->right));
		node->size = 1 + getSize(node->left) + getSize(node->right);
	}

	// 从 node 结点开始 (含node结点) 逐个向上重新平衡二叉树， 并更新结点高度和元素数
	void rebalance(Node* node) {
		while (node != nullptr) {
			int oldHeight = node->height, oldSize = node->size;
			if (!isBalanced(node)) {
				node = restructure(tallGrandchild(node));
				recompute(node->left);
				recompute(node->right);
			}
			recompute(node);
			if (node->height == oldHeight && node->size == oldSize) {
				node = nullptr;
			} else {
				node = node->parent;
			}
		}
	}

	// 判断 node 结点是否平衡
	bool isBalanced(Node* node) {
		return abs(getHeight(node->left) - getHeight(node->right)) <= 1;
	}

	// 获取 node 结点更高的子树
	






};















