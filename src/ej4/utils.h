#pragma once

#include <vector>
#include <algorithm>

#define IMPOSSIBLE_MSG "insatisfactible"

struct Constraint {
  int j, i, b;
};

//Time complexity: O(|v|)
void printVector(const std::vector<int> &v);

//U: Searches vector v for the element x, returns it's index or -1 if it's not present
//Time complexity: O(|v|)
int indexOf(const std::vector<int> &v, const int x);
