

#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;


class SegmentTree {
private:   
    int n;
    vector<long long> tree;  
    vector<int> nums;
    void buildTree() {
        tree.resize(2 * n, 0);
        for (int i = 0; i < n; i++) {
            tree[i + n] = nums[i];
        }
        for (int i = n - 1; i > 0; i--) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }
    
public:    
    SegmentTree(vector<int>& number) {
        nums = number;
        n = nums.size();
        buildTree();
    }
    
    
   long long sumRange(int l, int r) {
       l += n;
       r += n;
       long long sum = 0;
       while (l <= r) {
           if (l % 2 == 1) {
               sum += tree[l];
               l++;
           }
           if (r % 2 == 0) {
               sum += tree[r];
               r--;
           }
           l = l / 2;
           r = r / 2;  
       }
       return sum;  
   } 
};


class Solution {
    
    
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        SegmentTree st(nums);
        
        multimap<int, int> m;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            m.insert(std::pair<int, int>(nums[i], i));
            if ((long long)nums[i] * nums[i] > res) {
                res = (long long)nums[i] * nums[i];
            }
        }
        
        vector<int> v = {-1, n};
        set<int> s = {-1, n};
        for (auto& item : m) {
            long long val = item.first;
            int idx = item.second;
            auto iter = s.lower_bound(idx);
            int end = *iter;
            int start = *(--iter);
            long long sum = val * st.sumRange(start + 1, end - 1);
            if (sum > res) {
                res = sum;
            }
            s.insert(idx); 
        }  
        return (res % (int)(pow(10, 9) + 7));
    }
};









