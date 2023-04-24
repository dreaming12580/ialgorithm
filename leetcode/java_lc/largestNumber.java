package java_lc;


public class largestNumber {
	public class Solution {
		private void sort(int[] data, int lo, int hi) {
			if (lo >= hi) {
				return;
			}
			// 分区
			int pivot = data[hi];
			System.out.println("pivot:" + pivot);
			int less = lo;
			int great = hi;

			int i = lo;
			while (i <= great) {
				String xy = data[i] + "" + pivot;
				String yx = pivot + "" + data[i];
				System.out.println("xy:" + xy + ",yx:" + yx);
				if (xy.compareTo(yx) > 0) {
					swap(data, i, less);
					less++;
					i++;
				} else if (xy.compareTo(yx) < 0) {
					swap(data, i, great);
					great--;
				} else {
					i++;
				}
			}
			sort(data, lo, less - 1);
			sort(data, great + 1, hi);
		}

		public void swap(int[] nums, int i, int j) {
			int tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
		}
	
		public String largestNumber(int[] nums) {
			// 排序
			sort(nums, 0, nums.length - 1);
		
			if (nums[0] == 0) {
				return "0";   // "00000"
			}
		
			StringBuilder sb = new StringBuilder();
			for (int num : nums) {
				sb.append(num);
			}
			return sb.toString();
		}
	}

	Solution  newSolution() {
		return new Solution();
	}

	public static void main(String[] args) {
		int[] data = {3, 30, 34, 5, 9};
		largestNumber ln = new largestNumber();
		Solution s = ln.newSolution();
		String res = s.largestNumber(data);
		System.out.println(res);
	}
}












