#include "utils.h"

void init(AdjacencyMatrix& adj, int n) {
  adj.resize(n, {}); //A: n empty vectors
  for (int i = 0; i < n; i++) adj[i].reserve(n); //A: Each with enough space for n elements
}

void connect(AdjacencyMatrix& adj, int p, int q) { //U: Connects two nodes in the adjacency matrix
  adj[p].push_back(q);
  adj[q].push_back(p);
}
