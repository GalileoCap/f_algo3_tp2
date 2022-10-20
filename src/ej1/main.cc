#include <iostream>
#include <vector>

#ifdef DEBUG
#include <cstdio>
#endif // DEBUG

enum color_t {
  WHITE, GREY, BLACK
};

using AdjacencyMatrix = std::vector<std::vector<int>>;

void connect(AdjacencyMatrix& adj, int p, int q) {
  adj[p].push_back(q);
  adj[q].push_back(p);
}

int find(std::vector<int>& parent, int x) {
  if (parent[x] != x) parent[x] = find(parent, parent[x]);
  return parent[x];
}

void join(std::vector<int>& parent, int x, int y) {
  parent[find(parent, x)] = find(parent, y);
}

void dfsTimes(const AdjacencyMatrix& adj, int p, int& currTime, std::vector<int>& timeIn, std::vector<color_t>& color) {
  color[p] = GREY;
  timeIn[p] = currTime++;

  for (int q : adj[p])
    if (color[q] == WHITE)
      dfsTimes(adj, q, currTime, timeIn, color);

  color[p] = BLACK;
}

void dfsParent(const AdjacencyMatrix& adj, int p, std::vector<int>& parents) {
  for (int q : adj[p])
    if (parents[q] == -1) {
      parents[q] = p;
      dfsParent(adj, q, parents);
    }
}

int dfsBridge(const AdjacencyMatrix& adj, int p, const std::vector<int> timeIn, const std::vector<int>& parents, std::vector<bool>& bridgeWithParent) {
  int count = 0;
  for (int q : adj[p]) {
    if (parents[q] == p) count += dfsBridge(adj, q, timeIn, parents, bridgeWithParent);
    else {
      if (timeIn[q] < timeIn[p] && q != parents[p]) count++; //A: (p, q) is a back edge going up
      else if (timeIn[q] > timeIn[p]) count--; //A: (p, q) is a back edge going down
    }
  }
  bridgeWithParent[p] = count == 0 && parents[p] != p;
  return count;
}

int main(void) {
  while (true) {
    int R, C, Q; //U: Rooms, Corridors, Queries
    std::cin >> R >> C >> Q;
    if (R == 0 || C == 0 || Q == 0) break; //A: No more tests

    //A: Input the maze
    AdjacencyMatrix maze(R);
    for (int i = 0, A, B; i < C; i++) {
      std::cin >> A >> B; //A: Corridor between rooms A and B
      connect(maze, A-1, B-1); //NOTE: The data is 1-indexed
    }

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

    std::vector<int> group(R);
    for (int p = 0; p < R; p++) group[p] = p;

    for (int p = 0; p < R; p++) //NOTE: Skip over the first one
      if (bridgeWithParent[p])
        join(group, p, parents[p]);

    //A: Solve each query
    for (int query = 0, S, T; query < Q; query++) {
      std::cin >> S >> T;
      std::cout << (find(group, S-1) == find(group, T-1) ? "Y" : "N") << std::endl;
    }

    std::cout << "-" << std::endl; //A: Separator between test results
  }

  return 0;
}
