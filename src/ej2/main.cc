#include "utils.h"

#include <iostream>

struct DisjointSet {
  DisjointSet(int n);

  int unite(int v, int w);
  int find(int v);

  std::vector<int> repr;
  std::vector<int> size;
};

DisjointSet::DisjointSet(int n) : repr(n, -1), size(n, 1) {}

int DisjointSet::unite(int v, int w) {
  v = find(v); w = find(w);
  if (v == w) return size[v];
  if (size[v] < size[w]) std::swap(v, w);
  repr[w] = v;
  return size[v] += size[w];
}

int DisjointSet::find(int v) {
  return (repr[v] == -1) ? v : repr[v] = find(repr[v]);
}

int main(void) {
  int T; //U: Number of test cases
  std::cin >> T;

  for (int test = 0; test < T; test++) {
    int n, m; //U: |V|, |E|
    std::cin >> n >> m;

    //A: Input the weighed graph; O(n + m)
    struct DisjointSet set(n);
    std::vector<struct Edge> edges(m);
    for (int i = 0, v, w, k; i < m; i++) {
      std::cin >> v >> w >> k;
      v--; w--; //NOTE: The input is 1-indexed
      edges[i] = {v, w, k};
    }

    //A: Sort the edges by heaviest to lightest; O(m log(m)) <= O(m log(n^2)) = O(2m log(n)) = O(m log(n))
    std::sort(edges.begin(), edges.end(), Edge::greaterThan);

    int res = 0;
    for (const struct Edge& e : edges) {
      int v = e.v, w = e.w, weight = e.weight;
      if (set.find(v) != set.find(w)) {
        //TODO: if (weight > min (v, w) || ) {
        res += set.unite(v, w);
        //TODO: } Unite min v, w
#ifdef DEBUG
        printf("(%i, %i): %i\n", v+1, w+1, res);
#endif // DEBUG
      }
    }

    std::cout << res << std::endl;
  }

  return 0;
}
