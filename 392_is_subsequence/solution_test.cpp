#include "solution.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Own examples")
{
    Solution s;

    REQUIRE(s.isSubsequence("hello", "hello, world"));
    REQUIRE(s.isSubsequence("world", "hello, world"));
    REQUIRE(s.isSubsequence("oo", "hello, world"));
    REQUIRE(s.isSubsequence("", "hello, world"));
    REQUIRE(s.isSubsequence("", ""));

    REQUIRE(!s.isSubsequence("ooo", "hello, world"));
    REQUIRE(!s.isSubsequence("wh", "hello, world"));
    REQUIRE(!s.isSubsequence("woo", "hello, world"));
    REQUIRE(!s.isSubsequence("woo", ""));
}

TEST_CASE("Leetcode examples")
{
    Solution s;

    // Input: s = "abc", t = "ahbgdc"
    // Output: true
    REQUIRE(s.isSubsequence("abc", "ahbgdc"));

    // Input: s = "axc", t = "ahbgdc"
    // Output: false
    REQUIRE(!s.isSubsequence("axc", "ahbgdc"));
}
