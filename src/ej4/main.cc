#include<iostream>
#include "finiteSetRestrictedSDC.h"

// NO LEE EL MENOS
int main(void) {
  // k = ecuaciones; n = cant variables; m = size del conjunto D
  int tests, k, n, m; 
  std::vector<int> D;
  std::vector<std::vector<int>> equations;
  // vector<vector<int>> results;
   
  std::cin >> tests;
  
  while(tests > 0) {
    // Inputs
    // Problem variables
    std::cin >> k >> n >> m;
    equations.resize(k);
    D.resize(m,0);

    // Equations
    for(int times = 0; times < k; times++) {
      // xj - xi <= Bij
      int j, i, Bij;
      std::cin >> j >> i >> Bij;
      std::vector<int> diff = {j, i, Bij};
      equations[times] = diff;
    }
    
    // D set
    for (int times = 0; times < m; times++) {
      int Dk;
      std::cin >> Dk;
      D[times] = Dk;
    }

    // Algorithm
    finiteSetRestrictedSDC SRD(n, equations, D); 
    bool feasibleSolution = SRD.fishburnAlgorithm();
    
    if(feasibleSolution) {
      SRD.printSolutionSet();
    } else {
      std::cout << "insatisfactible" << std::endl;
    }
    tests--;
  }
  return 0;
}
