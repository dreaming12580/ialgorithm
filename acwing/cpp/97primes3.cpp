#include<iostream>
#include<unordered_map>
using namespace std;
typedef long long LL;

const int mod = 9901;
int A, B;

//保存质因子以及出现的次数
unordered_map<int, int> primes;

//试除法质因子分解
void divide(int n) {
    for(int i = 2; i <= n / i; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                primes[i]++;
                n /= i;
            }
        }
    }
    if(n > 1) {
        primes[n]++;
    }
}

//快速幂
int qmid(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    cin >> A >> B;

    //对A分解质因子
    divide(A);

    int res = 1;
    for(auto it : primes) {
        //p是质因子，k是质因子的次数
        int p = it.first, k = it.second * B;
        // res要乘上每一项, 注意这里是k + 1
        if((p - 1) % mod == 0) {  
            //不存在逆元，由于p - 1的是mod 的倍数, 故p % mod = 1
            //所以1 + p + ... + p^k每个数%mod 都是1，共k + 1个数，总就是k + 1
            res = (LL)res * (k + 1) % mod;
        }
        else{
            res = (LL)res * (qmid(p, k + 1) - 1) % mod * qmid(p - 1, mod - 2) % mod; 
        }

    }
    if(!A) res = 0;

    cout << (res % mod + mod ) % mod  << endl;

    return 0;
}
