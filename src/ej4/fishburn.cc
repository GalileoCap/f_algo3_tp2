#include "fishburn.h"

bool checkConstraints(
  const std::vector<struct Constraint> &constraints,
  const std::vector<int> &X
) {
  for (const struct Constraint &c : constraints)
    if (!((X[c.j] - X[c.i]) <= c.b)) return false;
  return true;
}

int getLargestIdx(
  const std::vector<int> &X,
  const std::vector<int> &Y,
  const std::vector<int> &D,
  const struct Constraint &c
) {
  for (int y = Y[c.j]; y > -1; y--)
    if ((D[y] - X[c.i]) <= c.b) //A: Solves
      return y;
  return -1;
}

bool fishburn(
  std::vector<int> &Y,
  const std::vector<struct Constraint> &constraints,
  const std::vector<int> &D
) {
  //NOTE: |X| = |Y|
  for (int &y : Y) y = D.size()-1; //A: Initialize every index to the maximum value's index; O(|Y|)
  std::vector<int> X(Y.size(), D[D.size()-1]); //A: Initialize every variable to the maximum value; O(|Y|)
  //TODO: Remove X to only use Y and D?

  bool changed;
  do {
    changed = false;
    for (const struct Constraint &c : constraints) {
      int largestIdx = getLargestIdx(X, Y, D, c); //NOTE: Since each Y is only going down from |D|-1 to -1, this is O(|Y| * |D|) by the final execution, doesn't change the complexity because O(|Y| * |constraints| * |D| + |Y| * |D|) = O(|Y| * |constraints| * |D|) //TODO: Better explanation
      if (!((X[c.j] - X[c.i]) <= c.b) && largestIdx != -1) { //A: Not currently solved and there's an element that does solve
        Y[c.j] = largestIdx;
        X[c.j] = D[largestIdx];
        changed = true;
      }
    }
  } while (changed);

  return checkConstraints(constraints, X);
}
