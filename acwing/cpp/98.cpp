
#include <iostream>
#include <cmath>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;

PLL calc(LL n, LL m) {
    if(n == 0) return {0, 0};
    LL len = 1ll << (n - 1); // n - 1级图构成n级图平移时的单位长度
    LL cnt = 1ll << (n - 1) * 2; // n - 1级图中所含的元素个数
    LL cnk = m / cnt; // 在n级图中，编号为m的元素所属块的编号
    LL idx = m % cnt; // 在n级图中，编号为m的元素在所属块中的编号
    PLL pos = calc(n - 1, idx); // 在n级图中，编号为m的元素在所属块中的坐标
    LL x = pos.x, y = pos.y;
    // 根据n级图中某个块的编号和这个块中某个元素的坐标，确定n - 1级图的坐标变换
    // 注意：离散坐标系跟实数坐标系有些许差别，不考虑这些差别
    // 结果必然是抓耳挠腮。hh
    if(cnk == 0) return {y, x}; // 没有平移，虽是旋转，坐标关系容易确定
    if(cnk == 1) return {x, y + len}; // 单纯平移
    if(cnk == 2) return {x + len, y + len}; // 单纯平移
    if(cnk == 3) return {len * 2 - y - 1, len - x - 1}; // 旋转又平移
}

LL rounding(double a) {
    LL b;
    if(a > 0) b = (a * 2 + 1) / 2;
    else b = (a * 2 - 1) / 2;  
    return b;
}

int main() {
    int times;
    cin >> times;
    while(times--) {
        LL n, a, b;
        cin >> n >> a >> b;
        PLL pa = calc(n, a - 1);
        PLL pb = calc(n, b - 1);
        //double x = pa.x - pb.x, y = pa.y - pb.y;
        //printf("%.0lf\n", sqrt(x * x + y * y) * 10.00);
        LL x = pa.x - pb.x, y = pa.y - pb.y;
        double dist = sqrt(x * x + y * y);
        cout << rounding(dist) << endl;
    }
    return 0;
}


作者：小小蒟蒻
链接：https://www.acwing.com/solution/content/16524/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。