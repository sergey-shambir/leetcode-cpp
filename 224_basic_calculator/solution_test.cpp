#include "solution.h"

#include <catch2/catch_test_macros.hpp>

namespace
{
int calculate(string s)
{
    Solution sol;
    return sol.calculate(s);
}
} // namespace

TEST_CASE("Own examples")
{
    REQUIRE(calculate("1251") == 1251);

    REQUIRE(calculate("1251+17") == 1268);
    REQUIRE(calculate("1251-17") == 1234);

    REQUIRE(calculate("1251 +  17") == 1268);
    REQUIRE(calculate("  1251  - 17  ") == 1234);

    REQUIRE(calculate("1251 + 17 - 1004 + 20") == 284);
    REQUIRE(calculate("1251 + 17 - 1004 - 20") == 244);
    REQUIRE(calculate("1251 + 17 - (1004 - 20)") == 284);
}

TEST_CASE("Leetcode examples")
{
    REQUIRE(calculate("1 + 1") == 2);
    REQUIRE(calculate(" 2-1 + 2 ") == 3);
    REQUIRE(calculate("(1+(4+5+2)-3)+(6+8)") == 23);
}
