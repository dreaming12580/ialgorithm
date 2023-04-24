

class Node:
	def __init__(self, key="", count=0):
		self.prev = None
		self.next = None  
		self.keys = {key} 
		self.count = count   
	
	# 在 self 后插入 node
	def inert(self, node: 'Node') -> 'Node':
		node.prev = self    
		node.next = self.next
		node.prev.next = node
		node.next.prev = node
		return node

	# 从链表中移除 self
	def remove(self):
		self.prev.next = self.next
		self.next.prev = self.prev


class AllOne:
	def __init__(self):
		self.root = Node()
		self.root.prev = self.root
		# 初始化链表哨兵， 下面判断节点的 next 若为 self.root, 则表示 next为空(prev同理)
		self.root.next = self.root
		self.nodes = {}

	def inc(self, key: str) -> None:
		# key 不在链表中
		if key not in self.nodes:
			if self.root.next is self.root or self.root.next.count > 1:
				self.nodes[key] = self.root.insert(Node(key, 1))
			else:
				self.root.next.keys.add(key)
				self.nodes[key] = self.root.next

