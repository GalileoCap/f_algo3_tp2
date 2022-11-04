#include "finiteSetRestrictedSDC.h"

finiteSetRestrictedSDC::finiteSetRestrictedSDC(int n, std::vector<std::vector<int>> equations, std::vector<int> D) {
  int m = D.size();
  this->n = n;
  this->D = D;
  this->solution.resize(n, m);
  
  for(std::vector<int> &var: equations) {
    assert((1 <= var[0] <= n) && (1 <= var[1] <= n));
    struct constraint newConstraint;
    newConstraint.xj = var[0]; // index j-1
    newConstraint.xi = var[1]; // index i-1
    newConstraint.Bij = var[2];

    this->constraints.push_back(newConstraint);
  }
}

// Fishburn's paper algorithm
bool finiteSetRestrictedSDC::fishburnAlgorithm() {    
  bool changed = true;
  
  while(changed) { // O(k*n*m)?
    changed = false;
    for(constraint &diff: constraints) { // O(k) * O(m)
      int DIndex = searchMaxDIdx(D[solution[diff.xi-1]-1] + diff.Bij); // O(m)
      if((DIndex != -1) &&
        (D[solution[diff.xj-1]-1] > D[solution[diff.xi-1]-1] + diff.Bij) &&
        (D[DIndex] <= D[solution[diff.xi-1]-1] + diff.Bij)) {
          solution[diff.xj - 1] = DIndex+1;
          changed = true;
      }
    }

  }

  bool feasibleSolution = !constraintViolated(); // O(k*m*n)?
  return feasibleSolution;
}

// Search max e s.t. e is an element of D and e is lesser than benchmark 
int finiteSetRestrictedSDC::searchMaxDIdx(int benchmark) {
  int i = 0;
  while(i < D.size() && D[i] <= benchmark) {
    i++;
  }
  return i-1;
}

// Check if there's a constraint that is being violated
// (there won't be any feasible solution)
bool finiteSetRestrictedSDC::constraintViolated() {
  int i = 0;
  bool violation = false;
  while(i < constraints.size()) {
    violation = (D[solution[constraints[i].xj-1]-1] - D[solution[constraints[i].xi-1]-1]) > constraints[i].Bij;
    if(violation) break;
    i++;
  }
  return violation;
}

// Print solution set
void finiteSetRestrictedSDC::printSolutionSet() {
  for (int i = 0; i < solution.size(); i++) {
    std::cout << solution[i] << " ";
    if(i == solution.size()-1) std::cout << std::endl; 
  }
}