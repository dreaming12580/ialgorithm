

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int backtrack(vector<int>& bit, vector<int>& vlen, int curr, int idx) {
        int n = bit.size();
        int res = 0;
        int i = idx;
        for (; i < n; ++i) {
            if (((curr & (1 << i)) == 0) && ((bit[i] & (1 << i)) == 0)) {
                curr ^= (1 << i);
                int temp = vlen[i];
                temp += backtrack(bit, vlen, curr | bit[i], i);
                res = max(res, temp);
                curr ^= (1 << i);
            }
        }
        return res;
    }

public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<vector<int>> hash(26, vector<int>());
        vector<int> vlen;
        vector<int> bit(n, 0);
        for (int i = 0; i < n; ++i) {
            string val = arr[i];
            for (char c : val) {
                hash[c - 'a'].push_back(i);
            }
            vlen.push_back(val.length());
        }
        for (int t = 0; t < 26; ++t) {
            auto v = hash[t];
            int m = v.size();
            for (int i = 0; i < m; ++i) {
                for (int j = i + 1; j < m; ++j) {
                    bit[v[i]] |= (1 << v[j]);
                    bit[v[j]] |= (1 << v[i]);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if ((bit[i] & (1 << i)) == 0) {
                int temp = vlen[i] + backtrack(bit, vlen, bit[i] | (1 << i), i);
                cout << "i: " << i << ",temp:" << temp << endl;
                res = max(res, temp);
            }
            
        }
        return res;
    }
};











