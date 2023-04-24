#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;



class Solution {
public:
	int smallestChair(vector<vector<int>>& times, int targetFriend) {
		int n = times.size();
		// 到达操作的时刻和对应的人
		vector<pair<int, int>> arrival; 
		// 离开操作的时刻和对应的人
		vector<pair<int, int>> leaving;  
		for (int i = 0; i < n; ++i) {
			arrival.emplace_back(times[i][0], i);
			leaving.emplace_back(times[i][1], i);
		}
		// 将到达与离开操作按照时间升序排序以方便模拟
		sort(arrival.begin(), arrival.end());
		sort(leaving.begin(), leaving.end());  
		// 未被占据的椅子
		priority_queue<int, vector<int>, greater<int>> available;
		for (int i = 0; i < n; ++i) {
			available.push(i);
		}
		// 每个人占据的椅子
		unordered_map<int, int> seats;
		// 双指针模拟
		int j = 0;
		for (auto&& [time, person] : arrival) {
			// 处理到达时间与之前的离开操作
			// 将释放的椅子加入未被占据椅子中
			while (j < n && leaving[j].first <= time) {
				available.push(seats[leaving[j].second]);
				++j;
			}
			// 处理到达操作
			// 占据当前编号最小且未被占据的椅子
			int seat = available.top(); 
			seats[person] = seat;
			available.pop();
			if (person == targetFriend) {
				// 如果当前人为目标， 则返回对应的椅子
				return seat;
			}
		}
		return -1;
	}
};













