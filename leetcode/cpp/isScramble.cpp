#include <string>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        int n = s1.size();
        if (n == 1) {
            return false;
        }
        return traverse(s1, 0, n - 1, s2, 0, n - 1);
    }

    bool traverse(const string& s1, int l1, int r1,
                  const string& s2, int l2, int r2) {
 
    cout << "begin l1:" << l1 << ", r1:" << r1 
            << ", l2:" << l2 << ", r2:" << r2 << endl;  
        while (l1 <= r1) {
            bool c = false;
            if (s1[l1] == s2[l2] && s1[l1] == s2[r2]) {
                return traverse(s1, l1+1, r1, s2, l2+1, r2) ||
                    traverse(s1, l1+1, r1, s2, l2, r2-1);
            } else if (s1[r1] == s2[l2] && s1[r1] == s2[r2]) {
                return traverse(s1, l1, r1-1, s2, l2+1, r2) ||
                    traverse(s1, l1, r1-1, s2, l2, r2-1);
            }
            
            if (s1[l1] == s2[l2]) {
                l1++;
                l2++;
                c = true;
            }
            if (s1[l1] == s2[r2]) {
                l1++;
                r2--;
                c = true;
            }
            if (s1[r1] == s2[l2]) {
                r1--;
                l2++;
                c = true;
            }
            if (s1[r1] == s2[r2]) {
                r1--;
                r2--;
                c = true;
            }
            if (!c) {
                break;
            }
        }
        cout << "======l1:" << l1 << ", r1:" << r1 
            << ", l2:" << l2 << ", r2:" << r2 << endl;                 
        if (l1 > r1) {
            return true;
        }
        set<char> left;
        set<char> left2;
        set<char> right;
        int len = r1 - l1;
        int i = 0;
        bool is_reverse = false;
        while (i < len) {
            left.insert(s1[l1 + i]);
            left2.insert(s2[l2 + i]);
            right.insert(s2[r2 - i]);
            if (left == right) {
                is_reverse = true;
                break;
            }
            if (left == left2) {
                break;
            }
            i++;
        }
        if (i == len) {
            return false;
        } 
        if (is_reverse) {
            return traverse(s1, l1, l1 + i, s2, r2 - i, r2) &&
                traverse(s1, l1 +i +1, r1, s2, l2, l2 + len - i - 1);

        } else {
            return traverse(s1, l1, l1 + i, s2, l2, l2 + i) &&
                traverse(s1, l1 + i + 1, r1, s2, l2 + i + 1, r2);

        }
    }
};


int main() {

  string s1 = "babcbccbccbacbaccc";
  string s2 = "accacccacbcbcbbcbb";
  Solution s;
  bool res = s.isScramble(s1, s2);
  return 0;

}

