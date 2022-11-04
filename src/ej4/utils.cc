#include "utils.h"
#include <iostream>

void printVector(const std::vector<int> &v) {
  for (int i = 0; i < (v.size()-1); i++)
    std::cout << v[i] << ' ';
  std::cout << v[v.size()-1] << std::endl;
}

int indexOf(const std::vector<int> &v, const int x) {
  for (int i = 0; i < v.size(); i++)
    if (v[i] == x) return i;
  return -1;
}
