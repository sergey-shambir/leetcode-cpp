#include "solution.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

using Catch::Matchers::Equals;

vector<int> removeDuplicates(vector<int> nums)
{
    Solution s;
    int newSize = s.removeDuplicates(nums);

    std::vector<int> result(nums.begin(), nums.begin() + newSize);
    std::ranges::sort(result);

    return result;
}

// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
TEST_CASE("First example from leetcode")
{
    REQUIRE_THAT(removeDuplicates({ 1, 1, 2 }), Equals<int>({ 1, 1, 2 }));
}

// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
TEST_CASE("Second example from leetcode")
{
    REQUIRE_THAT(removeDuplicates({ 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 }), Equals<int>({ 0, 0, 1, 1, 2, 2, 3, 3, 4 }));
}

TEST_CASE("Own tests")
{
    REQUIRE_THAT(removeDuplicates({}), Equals<int>({}));
    REQUIRE_THAT(removeDuplicates({ 0 }), Equals<int>({ 0 }));
    REQUIRE_THAT(removeDuplicates({ 5, 5 }), Equals<int>({ 5, 5 }));
    REQUIRE_THAT(removeDuplicates({ 5, 5, 5 }), Equals<int>({ 5, 5 }));
    REQUIRE_THAT(removeDuplicates({ 5, 5, 5, 5 }), Equals<int>({ 5, 5 }));
    REQUIRE_THAT(removeDuplicates({ 5, 5, 5, 5, 5 }), Equals<int>({ 5, 5 }));
    REQUIRE_THAT(removeDuplicates({ 1, 2, 2, 5, 7, 7, 7, 11, 11, 11, 11 }), Equals<int>({ 1, 2, 2, 5, 7, 7, 11, 11 }));
    REQUIRE_THAT(removeDuplicates({ 1, 2, 2, 2, 3, 3, 4, 4, 4, 5, 6, 7, 8, 8, 9 }), Equals<int>({ 1, 2, 2, 3, 3, 4, 4, 5, 6, 7, 8, 8, 9 }));

    REQUIRE_THAT(removeDuplicates({ 1, 2 }), Equals<int>({ 1, 2 }));
    REQUIRE_THAT(removeDuplicates({ 1, 2, 3 }), Equals<int>({ 1, 2, 3 }));
    REQUIRE_THAT(removeDuplicates({ 1, 2, 3, 4 }), Equals<int>({ 1, 2, 3, 4 }));
    REQUIRE_THAT(removeDuplicates({ 1, 2, 3, 4, 5 }), Equals<int>({ 1, 2, 3, 4, 5 }));
}
