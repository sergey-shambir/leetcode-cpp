#include "solution.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Leetcode example #1")
{
    MinStack s;
    s.push(-2);
    REQUIRE(s.getMin() == -2);
    REQUIRE(s.top() == -2);

    s.push(0);
    REQUIRE(s.getMin() == -2);
    REQUIRE(s.top() == 0);

    s.push(-3);
    REQUIRE(s.getMin() == -3);
    REQUIRE(s.top() == -3);

    s.pop();
    REQUIRE(s.getMin() == -2);
    REQUIRE(s.top() == 0);
}

TEST_CASE("Leetcode example #2")
{
    // ["MinStack","push","push","push","push","getMin","pop","getMin","pop","getMin","pop","getMin"]
    // [[],        [2],    [0],   [3],   [0],[],[],[],[],[],[],[]]
    MinStack s;
    s.push(2);
    REQUIRE(s.getMin() == 2);
    REQUIRE(s.top() == 2);

    s.push(0);
    REQUIRE(s.getMin() == 0);
    REQUIRE(s.top() == 0);

    s.push(3);
    REQUIRE(s.getMin() == 0);
    REQUIRE(s.top() == 3);

    s.push(0);
    REQUIRE(s.getMin() == 0);
    REQUIRE(s.top() == 0);

    s.pop();
    REQUIRE(s.getMin() == 0);
    REQUIRE(s.top() == 3);

    s.pop();
    REQUIRE(s.getMin() == 0);
    REQUIRE(s.top() == 0);
}

