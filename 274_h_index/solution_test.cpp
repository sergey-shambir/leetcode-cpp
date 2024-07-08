#include "solution.h"
#include <iostream>

#include <catch2/catch_test_macros.hpp>

int hIndex(vector<int> citations)
{
    Solution s;
    return s.hIndex(citations);
}

// Input: citations = [3,0,6,1,5]
// Output: 3
TEST_CASE("First example from leetcode")
{
    REQUIRE(hIndex({ 3, 0, 6, 1, 5 }) == 3);
}

// Input: citations = [1,3,1]
// Output: 1
TEST_CASE("Second example from leetcode")
{
    REQUIRE(hIndex({ 1, 3, 1 }) == 1);
}
