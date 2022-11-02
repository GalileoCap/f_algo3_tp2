#include "utils.h"

void connect(AdjacencyMatrix& adj, const struct Edge &e) {
  adj[e.v].push_back(e);
}
