



class Solution {
public:
    int takeCharacters(string s, int k) {
        int a = count(s.begin(), s.end(), 'a');
        int b = count(s.begin(), s.end(), 'b');
        int c = count(s.begin(), s.end(), 'c');
        if (a < k || b < k || c < k) {
            return -1;
        }
        a -= k, b-=k, c -= k;
        // num记录a,b,c的数目， check为上限
        vector<int> num(3), check{a, b, c};
        int ans=INT_MAX, i, j;
        for (i = 0, j = 0; j < s.size(); ++j) {
            // 寻找滑动窗口的最大长度
            num[s[j] - 'a']++;
            if (num[s[j] - 'a'] > check[s[j] - 'a']) {
                while (num[s[j] - 'a'] > check[s[j] - 'a']) {
                    num[s[i] - 'a']--;
                    ++i;
                }
            }
            ans = min(n - (j - i + 1), ans);
        }
        return ans;
    }
};




















