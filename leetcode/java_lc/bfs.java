package java_lc;

import java.util.Queue;
import java.util.Set;
import java.util.ArrayDeque;
import java.util.HashSet;

public class bfs {
  public class Node {
    Node[] abj;

    Node[] abj() {
      return abj;
    }

    Node() {

    }

    Node(Node other) {
      this.abj = other.abj;
    }

  }

  // 计算从起点start 到终点target的最近距离

  int BFS(Node start, Node target) {
    Queue<Node> q = new ArrayDeque<>();  //核心数据结构
    Set<Node> visited = new HashSet<>();    //避免走回头路

    q.offer(start);    // 将起点加入队列
    visited.add(start);
    int step = 0;      // 记录扩散的步数

    while (!q.isEmpty()) {
      int sz = q.size();
      /* 将当前队列中的所有节点向四周扩散 */
      for (int i = 0; i < sz; i++) {
        Node cur = q.poll();
        /* 划重点： 这里判断是否到达终点   */
        if (cur == target) {
          return step;
        }
        /* 将cur的相邻节点加入队列 */
        for (Node x : cur.abj()) {
          if (!visited.contains(x)) {
            q.offer(x);
            visited.add(x);
          }
        }
        /* 划重点： 更新步数在这里 */
        step++;
      }
    }
    return step;
  }
}


