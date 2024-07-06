#include "solution.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

using Catch::Matchers::Equals;

vector<int> removeElement(vector<int> nums, int val)
{
    Solution s;
    int newSize = s.removeElement(nums, val);

    std::vector<int> result(nums.begin(), nums.begin() + newSize);
    std::ranges::sort(result);

    return result;
}

// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_,_]
TEST_CASE("First example from leetcode")
{
    REQUIRE_THAT(removeElement({ 3, 2, 2, 3 }, 3), Equals<int>({ 2, 2 }));
}

// Input: Input: nums = [0,1,2,2,3,0,4,2], val = 2
// Output: 5, nums = [0,1,4,0,3,_,_,_]
TEST_CASE("Second example from leetcode")
{
    REQUIRE_THAT(removeElement({ 0, 1, 2, 2, 3, 0, 4, 2 }, 2), Equals<int>({ 0, 0, 1, 3, 4 }));
}
