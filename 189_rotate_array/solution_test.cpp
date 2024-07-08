#include "solution.h"
#include <iostream>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

using Catch::Matchers::Equals;

vector<int> rotate(vector<int> nums, int k)
{
    Solution s;
    s.rotate(nums, k);

    return nums;
}

TEST_CASE("Failed case from leetcode")
{
    REQUIRE_THAT(
        rotate({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27 }, 38),
        Equals<int>({ 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 }));
}

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
TEST_CASE("First example from leetcode")
{
    REQUIRE_THAT(rotate({ 1, 2, 3, 4, 5, 6, 7 }, 3), Equals<int>({ 5, 6, 7, 1, 2, 3, 4 }));
}

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
TEST_CASE("Second example from leetcode")
{
    REQUIRE_THAT(rotate({ -1, -100, 3, 99 }, 2), Equals<int>({ 3, 99, -1, -100 }));
}

TEST_CASE("Corner cases")
{
    REQUIRE_THAT(rotate({ -1 }, 2), Equals<int>({ -1 }));
    REQUIRE_THAT(rotate({ 1, 2, 3, 4 }, 1), Equals<int>({ 4, 1, 2, 3 }));
    REQUIRE_THAT(rotate({ 1, 2, 3, 4 }, 2), Equals<int>({ 3, 4, 1, 2 }));
    REQUIRE_THAT(rotate({ 1, 2, 3, 4 }, 3), Equals<int>({ 2, 3, 4, 1 }));
}

TEST_CASE("Own examples")
{
    REQUIRE_THAT(rotate({ 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 2), Equals<int>({ 8, 9, 1, 2, 3, 4, 5, 6, 7 }));
    REQUIRE_THAT(rotate({ 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 3), Equals<int>({ 7, 8, 9, 1, 2, 3, 4, 5, 6 }));
    REQUIRE_THAT(rotate({ 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 4), Equals<int>({ 6, 7, 8, 9, 1, 2, 3, 4, 5 }));
    REQUIRE_THAT(rotate({ 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 5), Equals<int>({ 5, 6, 7, 8, 9, 1, 2, 3, 4 }));
    REQUIRE_THAT(rotate({ 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 6), Equals<int>({ 4, 5, 6, 7, 8, 9, 1, 2, 3 }));
}
