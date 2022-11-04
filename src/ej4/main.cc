#include<iostream>
#include "finiteSetRestrictedSDC.h"

// NO LEE EL MENOS
int main(void) {
  // k = equations; n = unknowns; m = size of D set
  int tests, k, n, m; 
  std::vector<int> D;
  std::vector<std::vector<int>> equations;
  std::vector<bool> feasibleSolutions;
  std::vector<finiteSetRestrictedSDC> SRD; 
   
  std::cin >> tests;
  feasibleSolutions.resize(tests);

  while(tests > 0) {
    // Inputs
    // Unknowns for the problem
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
    finiteSetRestrictedSDC actualSRD(n, equations, D);
    feasibleSolutions[feasibleSolutions.size() - tests] = actualSRD.fishburnAlgorithm();
    SRD.push_back(actualSRD);
    tests--;
  }

  for (int i = 0; i < feasibleSolutions.size(); i++) {
    if(feasibleSolutions[i]) {
        SRD[i].printSolutionSet();
    } else {
        std::cout << "insatisfactible" << std::endl;
    }
  }

  return 0;
}
