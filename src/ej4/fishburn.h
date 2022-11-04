#pragma once

#include "utils.h"

//U: Check every constraint and return false if any fails
//Time complexity: O(|constraints|)
bool checkConstraints(
  const std::vector<struct Constraint> &constraints,
  const std::vector<int> &X
);

//U: Gets the index largest element in D that solves the constraint c given a current X
//Time complexity: O(|D|)
int getLargestIdx(
  const std::vector<int> &X,
  const std::vector<int> &D,
  const struct Constraint &c
);

//U: Solves a set of constraints given D possible values using Fishburn's algorithm, modifies Y for the indexes in D of a solution and returns false if impossible
//Time complexity: O(|Y| * |constraints| * |D|)
bool fishburn(
  std::vector<int> &Y,
  const std::vector<struct Constraint> &constraints,
  const std::vector<int> &D
); 
