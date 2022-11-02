#include "dijkstra.h"
#include <limits.h>
#include <queue>

struct Foo {
  int key;
  int value;

  struct Compare{
    bool operator()(
      const struct Foo& e,
      const struct Foo& f
    );
  };
};

bool Foo::Compare::operator()(const struct Foo &e, const struct Foo &f) {
  return e.value < f.value;
}

std::vector<int> dijkstra(const AdjacencyMatrix& adj, int source) {
  std::vector<int> dist(adj.size(), INT_MAX);
  std::priority_queue<struct Foo, std::vector<struct Foo>, struct Foo::Compare> queue;

  dist[source] = 0;
  queue.push({source, dist[source]});

  while (!queue.empty()) {
    int v = queue.top().key; queue.pop();

    for (struct Edge e : adj[v]) {
      int w = e.w, weight = e.weight;
      if (dist[w] > (dist[v] + weight)) {
        dist[w] = dist[v] + weight;
        queue.push({w, dist[w]});
      }
    }
  }

  return dist;
}
