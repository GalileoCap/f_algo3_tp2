#include "dfs.h"

void dfsTimes(
  const AdjacencyMatrix& adj,
  int p,
  int& currTime,
  std::vector<int>& timeIn,
  std::vector<color_t>& color
) {
  //A: Enter, this is the first time we see this node color it as "in process"
  color[p] = GREY;
  timeIn[p] = currTime++;

  for (int q : adj[p])
    if (color[q] == WHITE) //A: It hasn't been colored in
      dfsTimes(adj, q, currTime, timeIn, color);

  //A: Leave, color the node as "done"
  color[p] = BLACK;
}

void dfsParent(
  const AdjacencyMatrix& adj,
  int p,
  std::vector<int>& parents
) {
  for (int q : adj[p])
    if (parents[q] == -1) { //A: It hasn't been reached yet, we're it's parent and continue from it
      parents[q] = p;
      dfsParent(adj, q, parents);
    }
}

int dfsBridge(
  const AdjacencyMatrix& adj,
  int p,
  const std::vector<int> timeIn,
  const std::vector<int>& parents,
  std::vector<bool>& bridgeWithParent
) {
  int count = 0;
  for (int q : adj[p]) {
    if (parents[q] == p)
      count += dfsBridge(adj, q, timeIn, parents, bridgeWithParent);
    else {
      if (timeIn[q] < timeIn[p] && q != parents[p]) count++; //A: (p, q) is a back edge going up
      else if (timeIn[q] > timeIn[p]) count--; //A: (p, q) is a back edge going down
    }
  }
  bridgeWithParent[p] = count == 0 && parents[p] != p;
  return count;
}

void dfsRoot(
  const AdjacencyMatrix& adj,
  int p,
  const std::vector<int>& parents,
  std::vector<int>& roots
) {
  for (int q : adj[p]) {
    if (parents[q] == p) {
      roots[q] = roots[p];
      dfsRoot(adj, q, parents, roots);
    }
  }
}
