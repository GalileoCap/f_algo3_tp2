#pragma once

#include "utils.h"

using DisjointSet = std::vector<int>;

//U: Returns the group representative for x
//Time complexity: O(alpha(|set|)) ~~~> O(1)
int find(
  DisjointSet& set,
  int x
);

//U: Joins two trees
//Time complexity: O(alpha(|set|)) ~~~> O(1)
void join(
  DisjointSet& set,
  int x,
  int y
);
