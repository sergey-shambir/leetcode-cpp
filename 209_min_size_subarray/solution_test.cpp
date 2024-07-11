#include "solution.h"

#include <catch2/catch_test_macros.hpp>

int minSubArrayLen(int target, vector<int> nums)
{
    Solution s;
    return s.minSubArrayLen(target, nums);
}

TEST_CASE("Cases from leetcode")
{
    REQUIRE(minSubArrayLen(7, {2,3,1,2,4,3}) == 2);
    REQUIRE(minSubArrayLen(4, {1,4,4}) == 1);
    REQUIRE(minSubArrayLen(11, {1,1,1,1,1,1,1,1}) == 0);

    REQUIRE(minSubArrayLen(213, {12,28,83,4,25,26,25,2,25,25,25,12}) == 8);
}

TEST_CASE("Own cases")
{
    REQUIRE(minSubArrayLen(11, {1,1,1,1,1,1,1,1,1,2,1,2,2}) == 8);
    REQUIRE(minSubArrayLen(11, {1,1,1,1,1,1,1,1,1,1,1,1,1,1}) == 11);
    REQUIRE(minSubArrayLen(11, {1,1,1,1,1,1,1,1,1,1,1,1,1}) == 11);
    REQUIRE(minSubArrayLen(11, {1,1,1,1,1,1,1,1,1,1,1,1}) == 11);
    REQUIRE(minSubArrayLen(11, {1,1,1,1,1,1,1,1,1,1,1}) == 11);
    REQUIRE(minSubArrayLen(11, {1,1,1,1,1,1,1,1,1,1,2}) == 10);
    REQUIRE(minSubArrayLen(11, {1,1,1,1,1,1,1,1,1,2}) == 10);
}
