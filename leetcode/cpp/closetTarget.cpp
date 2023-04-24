
class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        unordered_map<string, vector<int>> cnt;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            cnt[words[i]].push_back(i);
        }
        if (cnt.find(target) == cnt.end()) {
            return -1;
        }
        auto vec = cnt[target];
        int res = n;
        for (auto v : vec) {
            res = min(res, (v - startIndex + n) % n);
            res = min(res, (startIndex - v + n) % n);
        }
        return res;
    }
};


