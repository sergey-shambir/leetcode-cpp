#include "solution.h"

#include <catch2/catch_test_macros.hpp>

int evalRPN(std::vector<std::string> tokens)
{
    Solution s;
    return s.evalRPN(tokens);
}

TEST_CASE("First example from leetcode")
{
    REQUIRE(9 == evalRPN({ "2", "1", "+", "3", "*" }));
}

TEST_CASE("Second example from leetcode")
{
    REQUIRE(6 == evalRPN({ "4", "13", "5", "/", "+" }));
}

TEST_CASE("Third example from leetcode")
{
    REQUIRE(22 == evalRPN({ "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" }));
}


TEST_CASE("First wrong value from leetcode")
{
    REQUIRE(-1 == evalRPN({ "3","-4","+" }));
}
