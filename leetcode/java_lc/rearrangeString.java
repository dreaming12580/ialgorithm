package java_lc;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;

class Solution {

  public String rearrangeString(String s, int k) {
    if (k <= 1) {
      return s;
    }
    HashMap<Character, Integer> map = new HashMap<>();
    // 大顶堆
    PriorityQueue<Map.Entry<Character, Integer>> maxHeap = 
        new PriorityQueue<>((a, b) -> b.getValue() - a.getValue());
    for (Character c : s.toCharArray()) {
      // 遍历字符，统计字符的出现次数
      map.put(c, map.getOrDefault(c, 0) + 1);
    }
    // 装入大顶堆， 按照字符重复次数作为比较
    maxHeap.addAll(map.entrySet());
    StringBuilder sb = new StringBuilder(s.length());
    Queue<Map.Entry<Character, Integer>> queue = new LinkedList<>();
    while (!maxHeap.isEmpty()) {
      // 从大顶堆中取出重复次数最多的字符
      Map.Entry<Character, Integer> currentEntry = maxHeap.poll();
      sb.append(currentEntry.getKey());
      // 用掉一个字符， 次数减一
      currentEntry.setValue(currentEntry.getValue() - 1);
      queue.offer(currentEntry);
      // 在队列的长度到达 k的时候， 才将 entry 放会大顶堆
      if (queue.size() == k) {
        Map.Entry<Character, Integer> entry = queue.poll();
        if (entry.getValue() > 0) {
          maxHeap.add(entry);
        }
      }
    }
    return sb.length() == s.length() ? sb.toString() : "";
  }
};






















