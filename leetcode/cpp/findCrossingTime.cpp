// workL: 新仓库正在放箱的工人；
// waitL: 左边等待过桥的工人；
// waitR: 右边等待过桥的工人；
// workR: 旧仓库正在搬箱的工人；

class Solution {
public:
	int findCrossingTime(int n, int k, vector<vector<int>> &time) {
		stable_sort(time.begin(), time.end(), [](auto &a, auto &b) {
			return a[0] + a[2] < b[0] + b[2];
		});
		// < 工人在 time 中的索引下班， 在桥处的当前时间>
		priority_queue<pair<int, int>> waitL, waitR;
		// < 工人完成任务的截止时间， 工人在 time 中的索引下标>
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> workL, workR;
		for (int i = k - 1; i >= 0; --i) {
			waitL.emplace(i, 0);
		}
		int cur = 0;
		while (n) {
			while (!workL.empty() && workL.top().first <= cur) {
				auto [t, i] = workL.top(); 
				workL.pop();  
				// 左边完成放箱
				waitL.emplace(i, t);
			}
			while (!workR.empty() && workR.top().first <= cur) {
				auto [t, i] = workR.top(); 
				workR.pop(); 
				// 右边完成搬箱
				waitR.emplace(i, t);
			}
			// 右边过桥， 注意加到 waitR 中的都是 <= cur 的(下同)
			if (!waitR.empty()) {
				auto [i, t] = waitR.top(); 
				waitR.pop();
				cur += time[i][2];
				// 放箱
				workL.emplace(cur + time[i][3], i);
			} else if (!waitL.empty()) {
				// 左边过桥
				auto [i, t] = waitL.top(); 
				waitL.pop(); 
				cur += time[i][0];
				// 搬箱
				workR.emplace(cur + time[i][1], i);
				--n;
			} else if (workL.empty()) {
				// cur 过小， 找个最小的放箱/搬箱完成时间来更新 cur
				cur = workR.top().first;
			} else if (workR.empty()) {
				cur = workL.top().first;
			} else {
				cur = min(workL.top().first, workR.top().first);
			}
		}
		while (!workR.empty()) {
			// 右边完成搬箱
			auto [t, i] = workR.top();
			workR.pop();
			// 如果没有排队， 直接过桥；
			// 否则由于无论谁先过桥， 最终完成时间都是一样，所以也可以直接计算
			cur = max(t, cur) + time[i][2];
		}
		// 最后一个过桥的时间
		return cur;
	}
};














