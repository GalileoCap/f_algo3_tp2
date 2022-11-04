#include "utils.h"
#include "dijkstra.h"

#include <iostream>

int main(void) {
  int c; //U: Number of test cases
  std::cin >> c;

  for (int dataset = 0; dataset < c; dataset++) {
    int b, p; //NOTE: b = capacity of the box, p = |V|
    std::cin >> b >> p;

    //U: Input rules for the usher; O(|V|)
    AdjacencyMatrix adj(p+1), rev(p+1); //U: Regular adjacency matrix and reverse
    int q; std::cin >> q;
    for (int i = 0, w; i < q; i++) {
      std::cin >> w;
      connect(adj, {USHER, w, 0});
      connect(rev, {w, USHER, 0});
    }

    //U: Input rules for each parishioner; O(|V|+|E|)
    for (int v = 1, r, w, k; v <= p; v++) {
      std::cin >> r;
      for (int j = 0; j < r; j++) {
        std::cin >> k >> w;
        connect(adj, {v, w, k});
        connect(rev, {w, v, k});
      }
    }

#ifdef DEBUG
    for (int i = 0; i < adj.size(); i++) {
      printf("%i: ", i);
      for (const struct Edge &e : adj[i])
        printf("(%i, %i) ", e.w, e.weight);
      printf("\n");
    }
#endif // DEBUG

    //U: Calculate shortest distance between the every node and the usher; O(|E| log(|V|))
    std::vector<int> distance = dijkstra(adj, USHER);

    //U: Get the length of the shortest cycle containing the usher; O(|V|)
    int min = INT_MAX;
    for (const struct Edge &e : rev[USHER])
      if (distance[e.w] != INT_MAX && (distance[e.w] + e.weight) < min)
        min = distance[e.w] + e.weight;

    //U: Calculate the number of dollars the usher will be able to steal; O(1)
    int res = min < b ? ((b - min - 1) / (min-1) + 1) : 0;
    std::cout << res << std::endl;
  }

  return 0;
}
