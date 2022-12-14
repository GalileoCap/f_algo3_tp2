#pragma once

#include <climits>
#include <algorithm>
#include <vector>

#ifdef DEBUG
#include <cstdio>
#include <cstdarg>
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

void logMsg(const char msg[], ...); //U: Prints only if in debug mode
