#include "utils.h"
#include "dfs.h"

#include <iostream>

int main(void) {
  while (true) {
    int R, C, Q; //U: Rooms, Corridors, Queries; NOTE: |V| = R, |E| = C
    std::cin >> R >> C >> Q;
    if (R == 0 || C == 0 || Q == 0) break; //A: No more tests

    //A: Input the maze; O(C)
    AdjacencyMatrix maze(R);
    for (int i = 0, A, B; i < C; i++) {
      std::cin >> A >> B; //A: Corridor between rooms A and B
      connect(maze, A-1, B-1); //NOTE: The data is 1-indexed
    }

    //A: Calculate the parent and whether the connection with the parent is a bridge; O(R + C)
    std::vector<int> parents(R, -1);
    std::vector<int> times(R, -1);
    std::vector<color_t> colors(R, WHITE);
    std::vector<bool> bridgeWithParent(R, false);
    for (int p = 0, currTime = 0; p < R; p++)
      if (parents[p] == -1) {
        parents[p] = p;
        dfsParent(maze, p, parents);
        dfsTimes(maze, p, currTime, times, colors);
        dfsBridge(maze, p, times, parents, bridgeWithParent);
      }

#ifdef DEBUG
    for (int p = 0; p < R; p++)
      printf("%i: parent=%i, bridgeWithParent=%i\n", p, parents[p], (bridgeWithParent[p]) ? 1 : 0);
#endif // DEBUG

    //A: Rebuild the maze with only the bridges; O(R + C)
    AdjacencyMatrix onlyBridges(R);
    for (int p = 0; p < R; p++)
      if (bridgeWithParent[p])
        connect(onlyBridges, parents[p], p);

    //A: Identify each node in each tree by its root; O(R + C)
    std::vector<int> roots(R, -1);
    for (int p = 0; p < R; p++)
      if (roots[p] == -1) {
        roots[p] = p;
        dfsRoot(onlyBridges, p, parents, roots);
      }

    //A: Solve each query; O(1) each
    for (int query = 0, S, T; query < Q; query++) {
      std::cin >> S >> T;
      std::cout << (roots[S-1] == roots[T-1] ? "Y" : "N") << std::endl;
    }

    std::cout << "-" << std::endl; //A: Separator between test results
  }

  return 0;
}
