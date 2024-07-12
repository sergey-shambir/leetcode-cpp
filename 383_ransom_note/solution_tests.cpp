#include "solution.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Examples from leetcode")
{
    Solution s;

    // Input: ransomNote = "a", magazine = "b"
    // Output: false
    REQUIRE(!s.canConstruct("a", "b"));

    // Input: ransomNote = "aa", magazine = "ab"
    // Output: false
    REQUIRE(!s.canConstruct("aa", "ab"));

    // Input: ransomNote = "aa", magazine = "aab"
    // Output: true
    REQUIRE(s.canConstruct("aa", "aab"));
}
