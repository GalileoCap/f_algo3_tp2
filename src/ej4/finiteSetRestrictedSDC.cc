#include "finiteSetRestrictedSDC.h"

finiteSetRestrictedSDC::finiteSetRestrictedSDC(int n, std::vector<std::vector<int>> equations, std::vector<int> D) {
  int m = D.size()-1;
  this->n = n;
  this->solution.resize(n, D[m]);
  this->D = D;
  
  for(std::vector<int> &var: equations) {
    assert((1 <= var[0] <= n) && (1 <= var[1] <= n));
    struct constraint newConstraint;
    newConstraint.xj = var[0]; // index j-1
    newConstraint.xi = var[1]; // index i-1
    newConstraint.Bij = var[2];
    newConstraint.violated = true;

    this->constraints.push_back(newConstraint);
  }
}

// Fishburn's paper algorithm
bool finiteSetRestrictedSDC::fishburnAlgorithm() {    
  bool changed = true;
  
  while(changed) { // O(k*n*m)?
    changed = false;
    for(constraint &diff: constraints) { // O(k) * O(m)
      int Dk = searchMaxD(solution[diff.xi - 1] + diff.Bij); // O(m)
      if((solution[diff.xj - 1] > solution[diff.xi - 1] + diff.Bij) && 
        (Dk <= solution[diff.xi - 1] + diff.Bij)) {
          solution[diff.xj - 1] = Dk;
          diff.violated = false;
          changed = true;
      }
    }
  }
  
  bool feasibleSolution = !constraintViolated(); // O(k)
  return feasibleSolution;
}

// Search max e s.t. e is an element of D and e is lesser than benchmark 
int finiteSetRestrictedSDC::searchMaxD(int benchmark) {
  int result = NIL; // -infinity or bottom
  int i = 0;
  while(i < D.size() && D[i] < benchmark) {
    result = D[i];
    i++;
  }
  return result;
}

// Check if there's a constraint that is being violated
// (there won't be any feasible solution)
bool finiteSetRestrictedSDC::constraintViolated() {
  int i = 0;
  bool violation = false;
  while(i < constraints.size()) {
    violation = constraints[i].violated;
    if(violation) break;
  }
  return violation;
}

// Print solution set
void finiteSetRestrictedSDC::printSolutionSet() {
  for (int i = 0; i < solution.size(); i++) {
    std::cout << solution[i];
    if(i == solution.size()-1) std::cout << std::endl; 
  }
}