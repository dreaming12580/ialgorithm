package java_lc;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class serializeAnddeserialize2 {

	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;
		TreeNode(int x) {val = x; }
	}

	public class Codec {
		public String serialize(TreeNode root) {
			return rserialize(root, "");
		}

		public String rserialize(TreeNode root, String str) {
			if (root == null) {
				str += "None,";
			} else {
				str += String.valueOf(root.val) + ",";
				str = rserialize(root.left, str);
				str = rserialize(root.right, str);
			}
			return str;
		}

		public TreeNode deserialize(String data) {
			String[] dataArray = data.split(",");
			List<String> dataList = new LinkedList<String>(Arrays.asList(dataArray));
			return rdeserialize(dataList);
		}

		public TreeNode rdeserialize(List<String> dataList) {
			if (dataList.get(0).equals("None")) {
				dataList.remove(0);
				return null;
			}

			TreeNode root = new TreeNode(Integer.valueOf(dataList.get(0)));
			dataList.remove(0);
			root.left = rdeserialize(dataList);
			root.right = rdeserialize(dataList);

			return root;
		}








	}








	
}
