#include "solution.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

using Catch::Matchers::Equals;

vector<int> twoSum(vector<int> nums, int target)
{
    Solution s;
    return s.twoSum(nums, target);
}

TEST_CASE("Examples from leetcode")
{
    // Input: numbers = [2,7,11,15], target = 9
    // Output: [1,2]
    REQUIRE_THAT(twoSum({ 2, 7, 11, 15 }, 9), Equals<int>({ 1, 2 }));

    // Input: numbers = [2,3,4], target = 6
    // Output: [1,3]
    REQUIRE_THAT(twoSum({ 2, 3, 4 }, 6), Equals<int>({ 1, 3 }));

    // Input: numbers = [-1,0], target = -1
    // Output: [1,2]
    REQUIRE_THAT(twoSum({ -1, 0 }, -1), Equals<int>({ 1, 2 }));
}
