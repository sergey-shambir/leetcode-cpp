#include "solution.h"

#include <catch2/catch_test_macros.hpp>

bool containsNearbyDuplicate(vector<int> nums, int k)
{
    Solution s;
    return s.containsNearbyDuplicate(nums, k);
}

TEST_CASE("Leetcode examples")
{
    // Input: nums = [1,2,3,1], k = 3
    // Output: true
    REQUIRE(containsNearbyDuplicate({ 1, 2, 3, 1 }, 3));
    REQUIRE(containsNearbyDuplicate({ 1, 2, 3, 1 }, 4));
    REQUIRE(!containsNearbyDuplicate({ 1, 2, 3, 1 }, 2));
    REQUIRE(!containsNearbyDuplicate({ 1, 2, 3, 1 }, 1));

    // Input: nums = [1,0,1,1], k = 1
    // Output: true
    REQUIRE(containsNearbyDuplicate({ 1, 0, 1, 1 }, 1));

    // Input: nums = [1,2,3,1,2,3], k = 2
    // Output: false
    REQUIRE(!containsNearbyDuplicate({ 1, 2, 3, 1 }, 2));
    REQUIRE(containsNearbyDuplicate({ 1, 2, 3, 1 }, 3));
}
