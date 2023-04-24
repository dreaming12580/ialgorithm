package java_lc;

import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;

class Solution {

  private char[] word;
  private int patternLength;
  private String s;


  private boolean dfs(int idx1, int idx2, Map<Character, String> map, Set<String> hashSet) {
    if (idx1 == patternLength) {
      // 保证每个 s 没有未匹配的部分
      if (idx2 == s.length()) {
        return true;
      } else {
        return false;
      }
    }
    // 之前添加过
    if (map.containsKey(word[idx1])) {
      String str = map.get(word[idx1]);
      if (idx2 + str.length() <= s.length() && 
          s.substring(idx2, idx2 + str.length()).equals(str)) {
        return dfs(idx1 + 1, idx2 + str.length(), map, hashSet);
      } else {
        return false;
      }
    }
    
    // 没有添加过
    for (int i = idx2 + 1; i <= s.length(); ++i) {
      String str = s.substring(idx2, i);
      if (!hashSet.contains(str)) {
        hashSet.add(str);
        map.put(word[idx1], str);
        if (dfs(idx1 + 1, i, map, hashSet)) {
          return true;
        }
        map.remove(word[idx1]);
        hashSet.remove(str);
      }
    }
    return false;
  }

  public boolean wordPatternMatch(String pattern, String s) {
    word = pattern.toCharArray();
    patternLength = word.length;
    this.s = s;
    return dfs(0, 0, new HashMap<>(), new HashSet<>());
  }



}

















