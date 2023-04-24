

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i+1] = s[i] ^ arr[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j; k < n; ++k) {
                    if (s[i] == s[k + 1]) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }

    int countTriplets2(vector<int>& arr) {
        int n = arr.size();
        vector<int> s(n + 1);
        for(int i = 0; i < n; ++i) {
            s[i+1] = s[i] ^ arr[i];
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int k = i + 1; k < n; ++k) {
                if (s[i] == s[k+1]) {
                    ans += k - i;
                }
            }
        }
        return ans;
    }

    int countTriplets3(vector<int>& arr) {
        int n = arr.size();
        vector<int> s(n + 1);
        for (int i = 0; i < n; ++i) {
            s[i+1] = s[i] ^ arr[i];
        }
        unordered_map<int, int> cnt, total;
        int ans = 0;
        for (int k = 0; k < n; ++k) {
            if (cnt.count(s[k+1])) {
                ans += cnt[s[k + 1]] * k - total[s[k + 1]];
            }
            ++cnt[s[k]];
            total[s[k]] += k;
        }
        return ans;
    }

    int countTriplets4(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> cnt, total;
        int ans = 0, s = 0;
        for (int k = 0; k < n; ++k) {
            int val = arr[k];
            if (cnt.count(s ^ val)) {
                ans += cnt[s ^ val] * k - total[s ^ val];
            }
            ++cnt[s];
            total[s] += k;
            s ^= val;
        }
        return ans;
    }

    int countTriplets5(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> cnt, total;
        int ans = 0, s = 0;
        for (int k = 0; k < n; ++k) {
            int val = arr[k];
            // s ^ val 是前缀异或和 s[k+1]的值
            // 此时，cnt, total保存的是[0, k-1]的统计值
            if (cnt.count(s ^ val)) {
                ans += cnt[s ^ val] * k - total[s ^ val];
            }
            // s的值是前缀异或和 s[k]的值
            ++cnt[s];
            total[s] += k;
            s ^= val;
        }




    }




};

















