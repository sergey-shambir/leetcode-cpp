#include "solution.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

using Catch::Matchers::UnorderedEquals;

vector<int> twoSum(vector<int> nums, int target)
{
    Solution s;
    return s.twoSum(nums, target);
}

TEST_CASE("Leetcode examples")
{
    // Input: nums = [2,7,11,15], target = 9
    // Output: [0,1]
    REQUIRE_THAT(
        twoSum({ 2, 7, 11, 15 }, 9),
        UnorderedEquals<int>({ 0, 1 }));

    // Input: nums = [3,2,4], target = 6
    // Output: [1,2]
    REQUIRE_THAT(
        twoSum({ 3, 2, 4 }, 6),
        UnorderedEquals<int>({ 1, 2 }));

    // Input: nums = [3,3], target = 6
    // Output: [0,1]
    REQUIRE_THAT(
        twoSum({ 3, 3 }, 6),
        UnorderedEquals<int>({ 0, 1 }));

    REQUIRE_THAT(
        twoSum({ -1, -2, -3, -4, -5 }, -8),
        UnorderedEquals<int>({ 2, 4 }));

    REQUIRE_THAT(
        twoSum({ 0, 4, 3, 0 }, 0),
        UnorderedEquals<int>({ 0, 3 }));
}
