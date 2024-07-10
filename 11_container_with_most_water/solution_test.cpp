#include "solution.h"

#include <catch2/catch_test_macros.hpp>

int maxArea(vector<int> heights)
{
    Solution s;
    return s.maxArea(heights);
}

TEST_CASE("Examples from leetcode")
{
    REQUIRE(maxArea({ 1, 8, 6, 2, 5, 4, 8, 3, 7 }) == 49);
    REQUIRE(maxArea({ 1, 1 }) == 1);

    REQUIRE(maxArea({ 1,2,4,3 }) == 4);
}

TEST_CASE("Own examples")
{
    REQUIRE(maxArea({ 3, 3 }) == 3);
    REQUIRE(maxArea({ 3, 4 }) == 3);
    REQUIRE(maxArea({ 7, 4 }) == 4);

    REQUIRE(maxArea({ 4, 5, 6, 7, 8, 8, 7, 6, 5, 4 }) == 36);
    REQUIRE(maxArea({ 3, 4, 5, 6, 7, 8, 8, 7, 6, 5, 4, 3 }) == 36);
    REQUIRE(maxArea({ 3, 4, 5, 6, 7, 8, 7, 6, 5, 4, 3 }) == 32);
    REQUIRE(maxArea({ 3, 4, 5, 6, 7, 8, 9, 9, 8, 7, 6, 5, 4, 3 }) == 45);
    REQUIRE(maxArea({ 3, 5, 3, 5, 3, 5 }) == 20);
    REQUIRE(maxArea({ 3, 5, 3, 5 }) == 10);
}
