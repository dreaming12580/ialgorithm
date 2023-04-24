import itertools
class Solution:
	def isAlienSorted(self, words: List[str], order: str) -> bool:
		index = {c: i for i, c in enumerate(order)}
		return all(s <= t for s, t in pairwise([index[c] for word] for word in words))




