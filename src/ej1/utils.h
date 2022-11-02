#pragma once

#include <vector>

#ifdef DEBUG
#include <cstdio>
#endif // DEBUG

enum color_t {
  WHITE, GREY, BLACK
};

using AdjacencyMatrix = std::vector<std::vector<int>>;

//U: Initializes an AdjacencyMatrix for the maximum of n^2 elements
//Time complexity: O(n)
void init(AdjacencyMatrix& adj, int n);

//U: Connects two nodes in the adjacency matrix
//Time complexity: O(1)
void connect(AdjacencyMatrix& adj, int p, int q);
