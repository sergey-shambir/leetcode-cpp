#include "solution.h"

#include <catch2/catch_test_macros.hpp>

int trap(vector<int> height)
{
    Solution s;
    return s.trap(height);
}

TEST_CASE("Own example")
{
    REQUIRE(trap({ 5, 4, 3, 2, 1, 1, 3, 3 }) == 5);
    REQUIRE(trap({ 1 }) == 0);
    REQUIRE(trap({ 2, 5 }) == 0);
    REQUIRE(trap({ 5, 2, 5 }) == 3);
}

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
TEST_CASE("1st example from leetcode")
{
    REQUIRE(trap({ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }) == 6);
}

// Input: height = [4,2,0,3,2,5]
// Output: 9
TEST_CASE("2nd example from leetcode")
{
    REQUIRE(trap({ 4, 2, 0, 3, 2, 5 }) == 9);
}
