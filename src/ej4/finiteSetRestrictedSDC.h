#include<iostream>
#include<vector>
#include<assert.h>

#define NIL -1 // TODO: A que llamamos NIL? -infinito

/* We define the "difference constraint struct" as a representation of: 
   xj - xi <= Bij */
struct constraint {
  int xj; // index j-1 (or element j) for solution vector, not xj value.
  int xi; // index i-1 (or element i) for solution vector, not xi value.
  int Bij;
};

// System of Difference Constraints restricted by a finite set called "D" structure
struct finiteSetRestrictedSDC {
  // Variables
  int n;
  std::vector<int> solution;
  std::vector<constraint> constraints;
  std::vector<int> D;
  
  // Constructor
  finiteSetRestrictedSDC(int n, std::vector<std::vector<int>> equations, std::vector<int> D);

  // Fishburn's paper algorithm
  bool fishburnAlgorithm();

  // Search max e s.t. e is an element of D and e is lesser than benchmark 
  int searchMaxDIdx(int benchmark);

  // Check if there's a constraint that is being violated
  // (there won't be any feasible solution)
  bool constraintViolated();

  // Print solution set
  void printSolutionSet();
};