
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> bestLine(vector<vector<int>>& points) {
        vector<int> a(2);   //用来存满足条件的两个点
        int num;            //记录直线穿过点的数量
        int maxn = 0;       // 记录num的最大值
        int n = points.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // 先确定两个点
                num = 2;
                if (n - 1 - j + 1 + 1 <= maxn) {
                    break;
                }

                long long x1 = points[j][0] - points[i][0];
                long long y1 = points[j][1] - points[i][1];
                // 记录前两个点的向量 (x1, y1)
                for (int k = j + 1; k < n; ++k) {
                    // 不断更新第三个点
                    long long x2 = points[k][0] - points[i][0];
                    long long y2 = points[k][1] - points[i][1];
                    // 第三个点与第一个点构成的向量 (x2, y2)
                    if (x1 * y2 == x2 * y1) {
                        // 判断两个向量， 即三点是否共线
                        num++;
                    }
                }
                if (num > maxn) {
                    maxn = num;
                    a[0] = i;
                    a[1] = j;
                }
            }
        }
        return a;
    }
};














