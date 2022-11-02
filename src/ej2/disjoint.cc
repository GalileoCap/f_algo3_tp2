#include "disjoint.h"

DisjointSet::DisjointSet(int n) :
  repr(n, -1),
  data(n, {1, std::vector<int>(n, INT_MAX), std::vector<int>(n, INT_MIN)})
  {}

int& DisjointSet::size(int v) {
  return data[find(v)].size;
}

int& DisjointSet::max(int v, int w) {
  v = find(v); w = find(w);
  int &mvw = data[v].max[w],
      &mwv = data[w].max[v];
  mvw = std::max(mvw, mwv);
  mwv = std::max(mvw, mwv);
  return mwv;
}

int& DisjointSet::min(int v, int w) {
  v = find(v); w = find(w);
  int &mvw = data[v].min[w],
      &mwv = data[w].min[v];
  mvw = std::min(mvw, mwv);
  mwv = std::min(mvw, mwv);
  return mwv;
}

int DisjointSet::unite(int v, int w) {
  v = find(v); w = find(w);
  if (v == w) return size(v); //A: Nothing to do
  if (size(v) < size(w)) std::swap(v, w); //TODO: Is this needed?

  size(v) += size(w);
  for (int u = 0; u < repr.size(); u++) {
    max(v, u) = std::max(max(v, u), max(w, u));
    min(v, u) = std::min(min(v, u), min(w, u));
  }
  repr[w] = v;

  return size(v);
}

int DisjointSet::find(int v) {
  return (repr[v] == -1) ? v : repr[v] = find(repr[v]);
}

void DisjointSet::log(void) {
#ifdef DEBUG
  logMsg("    ");
  for (int v = 0; v < repr.size(); v++)
    if (v == find(v)) logMsg("  %i  ", v+1);
  logMsg("\n");

  for (int v = 0; v < repr.size(); v++) {
    if (v == find(v)) {
      logMsg("%i: ", v+1);
      for (int w = 0; w <= v; w++)
        if (v == w) {
          logMsg(" -");
          if (min(v, w) == INT_MAX) logMsg("/- ");
          else logMsg("/%i ", min(v, w));
        }
        else if (w == find(w)) {
          logMsg("% i", max(v, w));
          if (min(v, w) == INT_MAX) logMsg("/- ");
          else logMsg("/%i ", min(v, w));
        }
      logMsg("\n");
    }
  }

  logMsg("\n");
#endif // DEBUG
}
