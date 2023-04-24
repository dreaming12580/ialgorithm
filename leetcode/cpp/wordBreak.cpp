


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> hash;
        int maxn = INT_MIN, minn = INT_MAX;
        for (string& word: wordDict) {
            hash.insert(word);
            maxn = max(maxn, (int)word.length());
            minn = min(minn, (int)word.length());
        }
        deque<int> dq;
        dq.push_back(1);
        for (int i = 1; i <= n; ++i) {
            int curr = 0;
            int r = dq.size();
            for (int k = minn; k <= i && k <= maxn; ++k) {
                string t = s.substr(i - k, k);
                if (hash.count(t)) {
                    curr |= dq[r - k];
                }
            }
            dq.push_back(curr);
            if (dq.size() > maxn) {
                dq.pop_front();
            }
        }
        return dq.back();
    }
};











