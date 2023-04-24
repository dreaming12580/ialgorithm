
#include <vector>
#include <algorithm>

using namespace std;


class Solution {

public:

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (k * m > n) {
            return -1;
        }
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while (low < high) {
            int day = low + (high - low) / 2;
            if (canMake(bloomDay, day, m, k)) {
                high = day;
            } else {
                low = day + 1;
            }
        }
        return low;
    }

    bool canMake(vector<int>& bloomDay, int day, int m, int k) {
        int bouquets = 0;
        int flowers = 0;
        int n = bloomDay.size();
        for (int i = 0; i < n && bouquets < m; i++) {
            if (bloomDay[i] <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets == m;
    }



};










