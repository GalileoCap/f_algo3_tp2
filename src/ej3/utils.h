#pragma once

#include <climits>
#include <algorithm>
#include <queue>
#include <vector>

#ifdef DEBUG
#include <cstdio>
#endif // DEBUG

#define USHER 0

struct Edge {
  int v, w;
  int weight;
};

using AdjacencyMatrix = std::vector<std::vector<struct Edge>>;
void connect(AdjacencyMatrix& adj, const struct Edge &e); //U: Connects two nodes in the adjacency matrix
