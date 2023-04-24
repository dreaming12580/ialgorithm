#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getNext(string p) {
    int n = p.size();
    int k = -1, j = 0;
    vector<int> next(n, -1);
    while (j < n - 1) {
        if (k == -1 || p[j] == p[k]) {
            ++k; ++j;
            // 避免 ABAB这种情况， 出现第二个B没匹配，又去匹配第一个B的情况
            // next[j] = k;
            next[j] = (p[j] != p[k]) ? k : next[k];
        } else {
            k = next[k];
        }
    }
    return next;
}

int kmp(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<int> next = getNext(p);

    cout << "next:";
    for (auto i : next) {
        cout << i << " ";
    }
    cout << endl;

    int i = 0, j = 0;
    vector<int> res;
    while (i < m) {
        if (j == - 1 || s[i] == p[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
        if (j == n) {
            res.push_back(i - j);
        }
    }
    cout << "res:";
    for (auto i :res) {
        cout << i << " ";
    }
    cout << endl;
    return -1;
}

int main() {
    string s = "dajfalskdabcdabcdabdfe";
    // string p = "abcdabd";
    string p = "abcdab";
    kmp(s, p);
    return 0;
}



