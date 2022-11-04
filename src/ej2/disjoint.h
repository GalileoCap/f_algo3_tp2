#pragma once

#include "utils.h"

struct DisjointSet {
  struct Data {
    int size;
    std::vector<int> min; //A: Minimum out edge
    std::vector<int> max; //A: Maximum out edge
  };

  DisjointSet(int n);

  int unite(int v, int w);
  int find(int v);

  int& size(int v);
  int& max(int v, int w);
  int& min(int v, int w);
  
  void log(void);

  std::vector<int> repr;
  std::vector<struct Data> data;
};
