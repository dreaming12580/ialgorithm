
#include <vector>


using namespace std;



class Solution {

public:
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {

        // 计算两个正方形中心(cx1, cy1), (cx2, cy2)
        double cx1 = square1[0] + ((double)square1[2]) / 2;
        double cy1 = square1[1] + ((double)square1[2]) / 2;

        double cx2 = square2[0] + ((double)square2[2]) / 2;
        double cy2 = square2[1] + ((double)square2[2]) / 2;

        vector<pair<double, double>> res;  //候选顶点集
        // 处理特殊情况  cx1 == cx2 和  cy1 == cy2
        if (cx1 == cx2) {
            res.push_back({cx1, square1[1]});
            res.push_back({cx1, square2[1]});
            res.push_back({cx1, square1[1] + square1[2]});
            res.push_back({cx1, square2[1] + square2[2]});
        } else if (cy1 == cy2) {
            res.push_back({square1[0], cy1});
            res.push_back({square2[0], cy1});
            res.push_back({square1[0] + square1[2], cy1});
            res.push_back({square2[0] + square2[2], cy1});
        } else {
            // 直线方程 f(y)
            auto fy = [=](double y) -> double {
                const double k = (cy2 - cy1) / (cx2 - cx1);
                return k * (y - cy1) + cx1;
            };

            // 直线方程 f(x)
            auto fx = [=](double x) -> double {
                const double k = (cy2 - cy1) / (cx2 - cx1);
                return k * (x - cx1) + cy1;
            };

            for (auto& sq : {square1, square2}) {
                for (auto &p : vector<pair<double, double> > {
                    {fy(sq[1]), sq[1]},
                    
                })





            }





        }










    }







};























