#include "solution.h"

#include <catch2/catch_test_macros.hpp>

namespace {
    bool isMatch(std::string s, std::string p)
    {
        Solution solution;
        return solution.isMatch(s, p);
    }
}

TEST_CASE("Examples from leetcode")
{
    REQUIRE(isMatch("aa", "a") == false);
    REQUIRE(isMatch("aa", "a*") == true);
    REQUIRE(isMatch("ab", ".*") == true);
}

TEST_CASE("Own examples")
{
    REQUIRE(isMatch("aa", ".") == false);
}