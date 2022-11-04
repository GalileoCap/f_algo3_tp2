#include "gtest-1.8.1/gtest.h"
#include "../src/ej4/finiteSetRestrictedSDC.h"

// GLOBAL TESTS
TEST(GlobalTest4, solve_Consigna1) {
    // First example
    std::vector<int> problemSolution = {3,1,2};

    std::vector<int> DUno = {2,5,10};
    std::vector<std::vector<int>> equationsUno = {{2,1,-8}, {3,1,-5}};
    int nUno = 3;

    finiteSetRestrictedSDC SRDUno(nUno, equationsUno, DUno);
    bool fishburn = SRDUno.fishburnAlgorithm();

    EXPECT_TRUE(fishburn);
    EXPECT_EQ(SRDUno.solution, problemSolution);
}

TEST(GlobalTest4, solve_Consigna2) {
    // Second example
    std::vector<int> problemSolution = {3,3,3,3};

    std::vector<int> DDos = {3,6,9};
    std::vector<std::vector<int>> equationsDos = {{1,2,0}, {3,4,0}, {1,3,0}};
    int nDos = 4;
    
    finiteSetRestrictedSDC SRDDos(nDos, equationsDos, DDos);
    bool fishburn = SRDDos.fishburnAlgorithm();

    EXPECT_TRUE(fishburn);
    EXPECT_EQ(SRDDos.solution, problemSolution);
}

TEST(GlobalTest4, solve_Consigna2) {
    // Third example

    std::vector<int> DTres = {1,2,3};
    std::vector<std::vector<int>> equationsTres = {{2,1,-3}};
    int nTres = 2;
    
    finiteSetRestrictedSDC SRDTres(nTres, equationsTres, DTres);
    bool fishburn = SRDTres.fishburnAlgorithm();

    EXPECT_FALSE(fishburn);
}