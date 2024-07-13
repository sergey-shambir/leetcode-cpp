#include "solution.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Own examples")
{
    Solution sol;
    REQUIRE(sol.isHappy(1));

    REQUIRE(!sol.isHappy(4));
    REQUIRE(!sol.isHappy(16));
    REQUIRE(!sol.isHappy(99));
}

TEST_CASE("Leetcode examples")
{
    Solution sol;

    REQUIRE(sol.isHappy(1));
    REQUIRE(sol.isHappy(19));

    REQUIRE(!sol.isHappy(2));
}
