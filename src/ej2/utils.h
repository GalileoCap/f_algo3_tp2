#pragma once

#include <climits>
#include <algorithm>
#include <vector>

#ifdef DEBUG
#include <cstdio>
#endif // DEBUG

struct Edge {
  int v, w;
  int weight;

  //U: Calculates whether e > f, used for std::sort
  //Time complexity: O(1)
  static bool greaterThan(
    const struct Edge& e,
    const struct Edge& f
  );
};
