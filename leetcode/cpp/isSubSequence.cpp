



boolean isSubSequence(String s, String t) {
  int m = s.length(), n = t.length();
  // 对t 进行预处理
  ArrayList<Integer>[] index = new ArrayList[256];
  for (int i = 0; i < n; i++) {
    char c = t.charAt(i);
    if (index[c] == null) {
      index[c] = new ArrayList<>();
    }
    index[c].add(i);
  }

  //串t上的指针
  int j = 0;
  //借助index查找 s[i]
  for (int i = 0; i < m; i++) {
    char c = s.charAt(i);
    // 整个t 压根没有字符c
    if (index[c] == null) return false;
    int pos = left_bound(index[c], j);
    // 二分搜索区间中没有找到字符c
    if (pos == index[c].size()) {
      return false;
    }
    //向前移动指针 j
    j = index[c].get(pos) + 1;
  }
  return true;
}














