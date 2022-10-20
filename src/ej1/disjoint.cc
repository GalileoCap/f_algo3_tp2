#include "disjoint.h"

int find(DisjointSet& set, int x) {
  if (set[x] != x) set[x] = find(set, set[x]);
  return set[x];
}

void join(DisjointSet& set, int x, int y) {
  set[find(set, x)] = find(set, y);
}
