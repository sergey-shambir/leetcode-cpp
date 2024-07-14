#include "solution.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Own examples")
{
    Solution sol;
    REQUIRE(sol.simplifyPath("/") == "/");
    REQUIRE(sol.simplifyPath("/home") == "/home");
    REQUIRE(sol.simplifyPath("/home/") == "/home");
    REQUIRE(sol.simplifyPath("/home/sergey") == "/home/sergey");
    REQUIRE(sol.simplifyPath("/home/sergey/..") == "/home");
    REQUIRE(sol.simplifyPath("/home/sergey/./.") == "/home/sergey");
    REQUIRE(sol.simplifyPath("/home/sergey/../mikhail") == "/home/mikhail");
}

TEST_CASE("Leetcode examples")
{
    Solution sol;
    REQUIRE(sol.simplifyPath("/a/../../b/../c//.//") == "/c");
}
