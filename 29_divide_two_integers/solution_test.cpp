#include "solution.h"

#include <catch2/catch_test_macros.hpp>

int divide(int dividend, int divisor)
{
    Solution s;
    return s.divide(dividend, divisor);
}

TEST_CASE("Leetcode Examples")
{
    REQUIRE(divide(10, 3) == 3);
    REQUIRE(divide(7, -3) == -2);
}

TEST_CASE("Positive to positive")
{
    REQUIRE(divide(0, 3) == 0);
    REQUIRE(divide(1, 3) == 0);
    REQUIRE(divide(2, 3) == 0);
    REQUIRE(divide(3, 3) == 1);
    REQUIRE(divide(4, 3) == 1);
    REQUIRE(divide(5, 3) == 1);
    REQUIRE(divide(6, 3) == 2);
}

TEST_CASE("Negative to negative")
{
    REQUIRE(divide(-1, 3) == 0);
    REQUIRE(divide(-2, 3) == 0);
    REQUIRE(divide(-3, 3) == -1);
    REQUIRE(divide(-4, 3) == -1);
    REQUIRE(divide(-5, 3) == -1);
    REQUIRE(divide(-6, 3) == -2);
}

TEST_CASE("Min integer divident")
{
    REQUIRE(divide(-2147483648, -2) == 1073741824);
    REQUIRE(divide(-2147483648, 2) == -1073741824);
    REQUIRE(divide(-2147483648, 1) == -2147483648);
    REQUIRE(divide(-2147483648, -1) == 2147483647);
}

TEST_CASE("Max integer divident")
{
    REQUIRE(divide(2147483647, -2) == -1073741823);
    REQUIRE(divide(2147483647, 2) == 1073741823);
    REQUIRE(divide(2147483647, 1) == 2147483647);
    REQUIRE(divide(2147483647, -1) == -2147483647);
}

TEST_CASE("Min integer divisor")
{
    REQUIRE(divide(1, -2147483648) == 0);
    REQUIRE(divide(-1, -2147483648) == 0);
    REQUIRE(divide(-2147483648, -2147483648) == 1);
}
