#include <vector>


using namespace std;



class Solution {

public:

	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		int n = matrix[0].size();
		int row = 0, column = n - 1;
		while (row >= 0 && row < m && column >= 0 && column < n) {
			int val = matrix[row][column];
			if (val < target) {
				row++;
			} else if (val > target) {
				column--;
			} else {
				return true;
			}
		}
		return false;
	}











};













