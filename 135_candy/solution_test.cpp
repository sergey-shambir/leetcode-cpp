#include "solution.h"

#include <catch2/catch_test_macros.hpp>

int candy(vector<int> ratings)
{
    Solution s;
    return s.candy(ratings);
}

TEST_CASE("Own examples")
{
    REQUIRE(candy({ 1, 4, 7, 5, 6, 2, 3 }) == 12);
    REQUIRE(candy({ 5, 6, 5, 6, 5, 6, 5 }) == 10);
    REQUIRE(candy({ 1 }) == 1);
    REQUIRE(candy({ 1, 1 }) == 2);
    REQUIRE(candy({ 2, 1 }) == 3);
    REQUIRE(candy({ 1, 2 }) == 3);
}

// Input: ratings = [1,0,2]
// Output: 5
TEST_CASE("1st example from leetcode")
{
    REQUIRE(candy({ 1, 0, 2 }) == 5);
}

// Input: ratings = [1,2,2]
// Output: 4
TEST_CASE("2nd example from leetcode")
{
    REQUIRE(candy({ 1, 2, 2 }) == 4);
}
