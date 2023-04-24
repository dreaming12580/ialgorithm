package java_lc;
public class serializeAnddeserialize {

	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode(int x) {val = x; }
	}

	public class Codec {
		public String serialize(TreeNode root) {
			if (root == null) {
				return "X";
			}
			String left = "(" + serialize(root.left) + ")";
			String right = "(" + serialize(root.right) + ")";
			return left + root.val + right;
		}
		
		public TreeNode deserialize(String data) {
			int[] ptr = {0};
			return parse(data, ptr);
		}
		
		public TreeNode parse(String data, int[] ptr) {
			if (data.charAt(ptr[0]) == 'X') {
				++ptr[0];
				return null;
			}
			TreeNode cur = new TreeNode(0);
			cur.left = parseSubtree(data, ptr);
			cur.val = parseInt(data, ptr);
			cur.right = parseSubtree(data, ptr);
			return cur;
		}
	
		public TreeNode parseSubtree(String data, int[] ptr) {
			++ptr[0];
			TreeNode subtree = parse(data, ptr);
			++ptr[0]; 
			return subtree;
		}
	
		public int parseInt(String data, int[] ptr) {
			int x = 0, sgn = 1;
			if (!Character.isDigit(data.charAt(ptr[0]))) {
				sgn = -1;
				++ptr[0];
			}
			while (Character.isDigit(data.charAt(ptr[0]))) {
				x = x * 10 + data.charAt(ptr[0]++) - '0';
			}
			return x * sgn;
		}
	
	
	
	
	}
}



