#include "solution.h"

#include <catch2/catch_test_macros.hpp>

int findMinArrowShots(vector<vector<int>> points)
{
    Solution sol;
    return sol.findMinArrowShots(points);
}

TEST_CASE("Leetcode examples")
{
    // Input: points = [[10,16],[2,8],[1,6],[7,12]]
    // Output: 2
    REQUIRE(findMinArrowShots({ { 10, 16 }, { 2, 8 }, { 1, 6 }, { 7, 12 } }) == 2);

    // Input: points = [[1,2],[3,4],[5,6],[7,8]]
    // Output: 4
    REQUIRE(findMinArrowShots({ { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } }) == 4);

    // Input: points = [[1,2],[2,3],[3,4],[4,5]]
    // Output: 2
    REQUIRE(findMinArrowShots({ { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 } }) == 2);
}

TEST_CASE("Own examples")
{
    REQUIRE(findMinArrowShots({ { 1, 12 }, { 2, 9 }, { 3, 8 }, { 4, 5 }, { 4, 5 }, { 7, 17 }, { 8, 16 }, { 9, 15 }, { 10, 14 } }) == 2);
    REQUIRE(findMinArrowShots({ { 1, 2 } }) == 1);
}
