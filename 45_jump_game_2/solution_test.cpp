#include "solution.h"

#include <catch2/catch_test_macros.hpp>

int jump(vector<int> nums)
{
    Solution s;
    return s.jump(nums);
}

// Input: nums = [2,3,1,1,4]
// Output: 2
TEST_CASE("1st example from leetcode")
{
    REQUIRE(jump({ 2, 3, 1, 1, 4 }) == 2);
}

// Input: nums = [2,3,0,1,4]
// Output: 2
TEST_CASE("2nd example from leetcode")
{
    REQUIRE(jump({ 2, 3, 0, 1, 4 }) == 2);
}
