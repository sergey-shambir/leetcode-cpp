#include "solution.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

using Catch::Matchers::Equals;

vector<int> productExceptSelf(vector<int> nums)
{
    Solution s;
    return s.productExceptSelf(nums);
}

TEST_CASE("Own examples")
{
    REQUIRE_THAT(productExceptSelf({ 1, 2, 3, 4, 5 }), Equals<int>({ 2 * 3 * 4 * 5, 3 * 4 * 5, 2 * 4 * 5, 2 * 3 * 5, 2 * 3 * 4 }));
    REQUIRE_THAT(productExceptSelf({ 5, 4 }), Equals<int>({ 4, 5 }));
    REQUIRE_THAT(productExceptSelf({ 0, 0 }), Equals<int>({ 0, 0 }));
}

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
TEST_CASE("1st example from leetcode")
{
    REQUIRE_THAT(productExceptSelf({ 1, 2, 3, 4 }), Equals<int>({ 24, 12, 8, 6 }));
}

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
TEST_CASE("2nd example from leetcode")
{
    REQUIRE_THAT(productExceptSelf({ -1, 1, 0, -3, 3 }), Equals<int>({ 0, 0, 9, 0, 0 }));
}
