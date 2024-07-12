#include "solution.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Leetcode examples")
{
    Solution s;

    // Input: s = "anagram", t = "nagaram"
    // Output: true
    REQUIRE(s.isAnagram("anagram", "nagaram"));

    // Input: s = "rat", t = "car"
    // Output: false
    REQUIRE(!s.isAnagram("rat", "car"));
}
