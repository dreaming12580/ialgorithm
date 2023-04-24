


Graph graph;

boolean[] visited;


/* 图遍历框架 */

void traverse(Graph graph, int s) {
  if (visited[s]) return ;
  // 经过节点 s
  visited[s] = true;

  for (TreeNode neighbor : graph.neighbors(s)) {
    traverse(graph, neighbor);
  }

  // 离开节点 s
  visited[s] = false;
}















