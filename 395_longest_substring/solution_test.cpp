#include "solution.h"

#include <catch2/catch_test_macros.hpp>

int longestSubstring(std::string s, int k)
{
    Solution sol;
    return sol.longestSubstring(std::move(s), k);
}

TEST_CASE("Leetcode examples")
{
    REQUIRE(longestSubstring("aaabb", 3) == 3);
    REQUIRE(longestSubstring("ababbc", 2) == 5);
}

TEST_CASE("Own examples")
{
    REQUIRE(longestSubstring("aaabb", 2) == 5);
    REQUIRE(longestSubstring("aaabb", 4) == 0);
    REQUIRE(longestSubstring("ababbc", 3) == 0);
    REQUIRE(longestSubstring("abcdabcdabc", 3) == 0);
    REQUIRE(longestSubstring("abcabcdabc", 3) == 0);
    REQUIRE(longestSubstring("abcabcabc", 3) == 9);
}

TEST_CASE("Failed examples")
{
    REQUIRE(longestSubstring("ababacb", 3) == 0);
}
