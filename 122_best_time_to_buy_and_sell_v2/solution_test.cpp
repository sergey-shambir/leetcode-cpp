#include "solution.h"
#include <iostream>

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

using Catch::Matchers::Equals;

int maxProfit(vector<int> prices)
{
    Solution s;
    return s.maxProfit(prices);
}

// Input: prices = [7,1,5,3,6,4]
// Output: 7
TEST_CASE("First example from leetcode")
{
    REQUIRE(maxProfit({ 7, 1, 5, 3, 6, 4 }) == 7);
}

// Input: prices = [1,2,3,4,5]
// Output: 4
TEST_CASE("Second example from leetcode")
{
    REQUIRE(maxProfit({ 1, 2, 3, 4, 5 }) == 4);
}

// Input: prices = [7,6,4,3,1]
// Output: 0
TEST_CASE("Third example from leetcode")
{
    REQUIRE(maxProfit({ 7, 6, 4, 3, 1 }) == 0);
}
