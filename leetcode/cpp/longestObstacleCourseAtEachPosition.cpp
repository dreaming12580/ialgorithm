

#include <vector>



using namespace std;





class Solution {
public:
	vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
		vector<int> d, ans;
		for (int ob :  obstacles) {
			// 这里需要改成 >=
			if (d.empty() || ob >= d.back()) {
				d.push_back(ob);
				ans.push_back(d.size());
			}





		}











	}










};





















