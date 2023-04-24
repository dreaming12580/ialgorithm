package java_lc;
import java.util.Arrays;
import java.util.Comparator;


public class largestNumber2 {
	public class Solution {

		// 排序
		// 1.将所有元素转换成字符串
		public String largestNumber(int[] nums) {
			String[] strs = new String[nums.length];
			for (int i = 0; i < nums.length; ++i) {
				strs[i] = String.valueOf(nums[i]);
			}
			// 降序排列
			Arrays.sort(strs, new Comparator<String>() {
				@Override
				public int compare(String x, String y) {
					String xy = x + y;
					String yx = y + x;
					return yx.compareTo(xy);
				}
			});
			if (nums[0] == 0) {
				return "0";
			}
			StringBuilder sb = new StringBuilder();
			for (int num : nums) {
				sb.append(num);
			}
			return sb.toString();
		}
	}
}
