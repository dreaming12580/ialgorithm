


string palindrome(string& s, int l, int r) {
  // 防止索引越界
  while (l >= 0 && r < s.size()
          && s[i] == s[r]) {
    // 向两边展开
    l--; r++;
  }
  // 返回以 s[l] 和 s[r] 为中心的最长回文串
  return s.substr(l + 1, r - l - 1);
}

string longestPalindrome(string s) {
  string res;
  for (int i = 0; i < s.size(); i++) {
    // 以 s[i] 为中心的最长回文子串
    string s1 = palindrome(s, i, i);
    // 以 s[i] 和 s[i+1] 为中心的最长回文子串
    string s2 = palindrome(s, i, i+1);
    // res = longest(res, s1, s2)
    res = res.size() > s1.size() ? res : s1;
    res = res.size() > s2.size() ? res : s2;
  }
  return res;
}



/////////////

public String longestPalindrome(String s) {
  if (s.isEmpty()) {
    return s;
  }
  int n = s.length();
  boolean[][] dp = new boolean[n][n];
  int left = 0;
  int right = 0;
  for (int i = n - 2; i >= 0; i--) {
    dp[i][i] = true;
    for (int j = i + 1; j < n; j++) {
      dp[i][j] = s.charAt(i) == s.charAt(j) &&
            (j - i < 3 || dp[i + 1][j - 1]);
      if (dp[i][j] && right - left < j - i) {
        left = i;
        right = j;
      }
    }
  }
  return s.substring(left, right + 1);
}
















