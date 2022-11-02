#include "utils.h"
#include "dijkstra.h"

#include <iostream>

int main(void) {
  int c;
  std::cin >> c;

  for (int dataset = 0; dataset < c; dataset++) {
    int b, p;
    std::cin >> b >> p;

    AdjacencyMatrix adj(p+1); //TODO: Reserve p for each node
    int q; std::cin >> q;
    for (int i = 0, v; i < q; i++) {
      std::cin >> v;
      connect(adj, {v, USHER, -1});
    }

    for (int i = 1, r, w, k; i <= p; i++) {
      std::cin >> r;
      for (int j = 0; j < r; j++) {
        std::cin >> k >> w;
        connect(adj, {w, i, k});
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

    std::vector<int> shortest = dijkstra(adj, USHER);

    int min = shortest[1];
    for (int i = 1; i < shortest.size(); i++)
      min = std::min(min, shortest[i]);

    std::cout << (min < b ? b / (min-1) : 0) << std::endl;
  }

  return 0;
}
