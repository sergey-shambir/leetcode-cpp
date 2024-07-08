#include "solution.h"

#include <catch2/catch_test_macros.hpp>

bool canJump(vector<int> nums)
{
    Solution s;
    return s.canJump(nums);
}

// Input: nums = [2,3,1,1,4]
// Output: true
TEST_CASE("1st example from leetcode")
{
    REQUIRE(canJump({ 2, 3, 1, 1, 4 }) == true);
}

// Input: nums = [3,2,1,0,4]
// Output: false
TEST_CASE("2nd example from leetcode")
{
    REQUIRE(canJump({ 3, 2, 1, 0, 4 }) == false);
}

TEST_CASE("Failed example from leetcode")
{
    REQUIRE(canJump({ 0 }) == true);
}
