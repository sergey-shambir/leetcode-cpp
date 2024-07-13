#include "solution.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

using Catch::Matchers::Equals;

vector<string> summaryRanges(vector<int> nums)
{
    Solution s;
    return s.summaryRanges(nums);
}

TEST_CASE("Leetcode examples")
{
    // Input: nums = [0,1,2,4,5,7]
    // Output: ["0->2","4->5","7"]
    REQUIRE_THAT(summaryRanges({ 0, 1, 2, 4, 5, 7 }), Equals<string>({"0->2", "4->5", "7"}));

    // Input: nums = [0,2,3,4,6,8,9]
    // Output: ["0","2->4","6","8->9"]
    REQUIRE_THAT(summaryRanges({0,2,3,4,6,8,9 }), Equals<string>({"0","2->4","6","8->9"}));
}
