




#include <set>
#include <queue>


using namespace std;



class MKAverage {
public:
    long long m, k, sum = 0;
    multiset<int> lower, middle, upper;
    queue<int> nums;

    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }

    void shiftLeft(multiset<int>& l, multiset<int>& r) {
        l.insert(*r.begin());
        r.erase(r.begin());
    }

    void shiftRight(multiset<int>& l, multiset<int>& r) {
        r.insert(*l.rbegin());
        l.erase(--l.end());
    }

    void addElement(int num) {
        nums.push(num);

        if (lower.size() && *lower.rbegin() >= num) {
            lower.insert(num);
        } else if (upper.size() && *upper.begin() <= num) {
            upper.insert(num);
        } else {
            middle.insert(num);
            sum += num;
        }

        while(lower.size() > k) {
            sum += *lower.rbegin();
            shiftRight(lower, middle);
        }
        while (upper.size() > k) {
            sum += *upper.begin();
            shiftLeft(middle, upper);
        }

        if (nums.size() > m) {
            int d = nums.front(); 
            nums.pop();
            auto lit = lower.find(d);
            auto mit = middle.find(d);
            if (lit != lower.end()) {
                lower.erase(lit);
            } else if (mit != middle.end()) {
                middle.erase(mit);
                sum -= d;
            } else {
                upper.erase(upper.find(d));
            }
        }

        if (nums.size() >= m) {
            while (lower.size() < k) {
                sum -= *middle.begin();
                shiftLeft(lower, middle);
            }
            while (upper.size() < k) {
                sum -= *middle.rbegin();
                shiftRight(middle, upper);
            }
        }
    }

    int calculateMKAverage() {
        if (nums.size() < m) {
            return -1;
        }
        return sum / (m - 2 * k);
    }
};













