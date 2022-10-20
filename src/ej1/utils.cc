#include "utils.h"

void connect(AdjacencyMatrix& adj, int p, int q) { //U: Connects two nodes in the adjacency matrix
  adj[p].push_back(q);
  adj[q].push_back(p);
}
