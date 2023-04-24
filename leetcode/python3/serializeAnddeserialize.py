



from typing import Collection

class TreeNode(object):
	def __init__(self, x):
		self.val = x
		self.left = None
		self.right = None



class Codec:
	def serialize(self, root):
		if not root: return "[]"
		queue = Collection.deque()
		queue.append(root)
		res = []
		while queue:
			node = queue.popleft()
			if node:
				res.append(str(node.val))
				queue.append(node.left)
				queue.append(node.right)
			else:
				res.append("null")
		return '[' + ','.join(res) +']'

	def deserialize(self, data):
		if data == "[]": return
		vals, i = data[1:-1].split(','), 1
		root = TreeNode(int(vals[0]))
		queue = Collection.deque()
		queue.append(root)
		while queue:
			node = queue.popleft()
			if vals[i] != "null":
				node.left = TreeNode(int(vals[i]))
				queue.append(node.left)
			i += 1
			if vals[i] != "null":
				node.right = TreeNode(int(vals[i]))
				queue.append(node.right)
			i += 1
		return root





