#include "utils.h"
#include "fishburn.h"
#include <iostream>

int main(void) {
  int T;
  std::cin >> T;
  for (int test = 0; test < T; test++) {
    int k, n, m; //NOTE: k = |constraints|, n = |Y| = |X|, m = |D|
    std::cin >> k >> n >> m;

    //A: Input the constraints of the form a - b <= c or x_j - x_i <= b_ji; O(k)
    std::vector<struct Constraint> constraints(k);
    for (int i = 0, a, b, c; i < k; i++) {
      std::cin >> a >> b >> c;
      constraints[i] = {--a, --b, c}; //NOTE: Input is 1-indexed
    }

    //A: Input the possible values; O(m)
    std::vector<int> D(m);
    for (int i = 0, d; i < m; i++) std::cin >> D[i];
    //NOTE: D is already ordered

    //A: Get the vector of indexes using Fishburn's algorithm; O(kmn)
    std::vector<int> Y(n);
    bool check = fishburn(Y, constraints, D);
    
    if (check) { //A: Solved
      for (int &y : Y) y++; //A: Output is 1-indexed; O(n)
      printVector(Y); //A: Print the vector of indexes; O(n)
    } else std::cout << IMPOSSIBLE_MSG << std::endl; //A: Can't be solved
  }

  return 0;
}
