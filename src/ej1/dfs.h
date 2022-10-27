#pragma once

#include "utils.h"

//U: Recursively calculates the order in which each node gets accessed doing DFS from p
//Time complexity: O(|V| + |E|)
void dfsTimes(
  const AdjacencyMatrix& adj,
  int p,
  int& currTime,
  std::vector<int>& timeIn,
  std::vector<color_t>& color
);

//U: Calculates the parent of each node when doing DFS from p
//Time complexity: O(|V| + |E|)
void dfsParent(
  const AdjacencyMatrix& adj,
  int p,
  std::vector<int>& parents
);

//U: Calculates whether each edge on the tree is a bridge when doing DFS from p
//Time complexity: O(|V| + |E|)
int dfsBridge(
  const AdjacencyMatrix& adj,
  int p,
  const std::vector<int> timeIn,
  const std::vector<int>& parents,
  std::vector<bool>& bridgeWithParent
);

//U: Sets the root of the tree for each node when doing DFS from p
//Time complexity: O(|V| + |E|)
void dfsRoot(
  const AdjacencyMatrix& adj,
  int p,
  const std::vector<int>& parents,
  std::vector<int>& roots
);
