

class FirstUnique {
private:
    unordered_set<int>unique;
    unordered_set<int>repeated;
    vector<int>nums;
    int offset = 0;
public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            add(num);
        }
    }
    
    int showFirstUnique() {
        //没有unique的元素，直接返回-1
        if (unique.empty()) { 
            return -1;
        }
        //从offset开始遍历数组，找数组中第一个unique的元素
        for (int i=offset; i<nums.size(); ++i) {
            if (unique.count(nums[i])) {
                offset = i;
                return nums[i];
            }
        }
        return -1;
    }
    
    void add(int num) {
        //如果重复，从unique中移除，加入repeated
        if (unique.count(num)) {
             unique.erase(num);
             repeated.insert(num);
        } else {
        //如果不是repeated元素且第一次出现，加入unique
            if (!repeated.count(num)) {
                unique.insert(num);
                //加入数组
                nums.push_back(num);
            }
        }
    }
};













