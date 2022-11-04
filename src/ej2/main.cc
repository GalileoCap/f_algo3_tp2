#include "utils.h"
#include "disjoint.h"
#include <iostream>

int main(void) {
  int T; //U: Number of test cases
  std::cin >> T;

  for (int test = 0; test < T; test++) {
    int n, m; //U: |V|, |E|
    std::cin >> n >> m;
    logMsg("[test] %u %u %u\n", test+1, n, m);

    //A: Input the weighed graph; O(n + m)
    struct DisjointSet set(n);
    std::vector<struct Edge> edges(m);
    for (int i = 0, v, w, k; i < m; i++) {
      std::cin >> v >> w >> k;
      v--; w--; //NOTE: The input is 1-indexed
      edges[i] = {v, w, k};
      set.max(v, w) = k;
      set.min(v, w) = k;
    }
    set.log();

    //A: Sort the edges by heaviest to lightest; O(m log(m)) <= O(m log(n^2)) = O(2m log(n)) = O(m log(n))
    std::sort(edges.begin(), edges.end(), Edge::greaterThan);

    int res = 0;
    for (const struct Edge& e : edges) {
      int v = e.v, w = e.w, weight = e.weight;
      bool counts = true;
      if (set.find(v) != set.find(w)) {
        int sum = set.unite(v, w);
        for (int u = 0; u < n; u++)
          if (set.find(u) != set.find(v))
            counts &= set.min(v, v) > set.max(v, u);

        res += sum * counts;
        logMsg("(%i, %i): %C? %i\n", v+1, w+1, counts ? 'T' : 'F', set.unite(v, w));
        set.log();
      }
    }

    std::cout << res << std::endl;
  }

  return 0;
}
