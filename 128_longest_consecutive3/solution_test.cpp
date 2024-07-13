#include "solution.h"

#include <catch2/catch_test_macros.hpp>

int longestConsecutive(vector<int> nums)
{
    Solution s;
    return s.longestConsecutive(nums);
}

TEST_CASE("Examples from leetcode")
{
    // Input: nums = [100,4,200,1,3,2]
    // Output: 4
    REQUIRE(longestConsecutive({ 100, 4, 200, 1, 3, 2 }) == 4);

    // Input: nums = [0,3,7,2,5,8,4,6,0,1]
    // Output: 9
    REQUIRE(longestConsecutive({ 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 }) == 9);
}
